#include"PluginLoader.hpp"

void PluginLoader::loadDll() {
    WIN32_FIND_DATAA wfd;

    HANDLE const hFind = FindFirstFileA((pluginsPath + std::string("*.dll")).c_str(), &wfd);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::string dllFileName(wfd.cFileName);
            getFunc(dllFileName);
        } while (NULL != FindNextFileA(hFind, &wfd));

        FindClose(hFind);
    }
    else
    {
        throw std::exception("invalid plpugin path");
    }
}

void PluginLoader::getFunc(std::string const& fileName) {
    HMODULE hm = LoadLibraryA((pluginsPath + fileName).c_str());

    if (hm == nullptr) {
        throw std::exception("dll not found");
    }

    std::string funcName = fileName.substr(0, fileName.find(".dll"));

    unaryFunction ufunc = (unaryFunction)GetProcAddress(hm, "unaryFunction");

    if (ufunc == nullptr)
    {
        binaryFunction bfunc = (binaryFunction)GetProcAddress(hm, "binaryFunction");
        if (bfunc == nullptr)
        {
            throw std::exception("function not found");
        }

        binaryFunctions.insert(std::pair<std::string, binaryFunction>(funcName, bfunc));
    }
    else
    {
        unaryFunctions.insert(std::pair<std::string, unaryFunction>(funcName, ufunc));
    }
}

double PluginLoader::makeOperation(double const& a, std::string const& funcName, double const& b) {
    if (unaryFunctions.contains(funcName)) {
        return unaryFunctions[funcName](a);
    }
    else if (binaryFunctions.contains(funcName)) {
        return binaryFunctions[funcName](a, b);
    }
}

bool PluginLoader::containsUnaryFunc(std::string const& funcName) const{
    return unaryFunctions.contains(funcName);
}

bool PluginLoader::containsBinaryFunc(std::string const& funcName) const {
    return binaryFunctions.contains(funcName);
}

