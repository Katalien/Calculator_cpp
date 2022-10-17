#pragma once
#include<iostream>
#include<map>
#include<Windows.h>


using unaryFunction = double(*)(double);
using binaryFunction = double(*)(double, double);
using mapBinarFunction = std::map<std::string, double(*)(double, double)>;
using mapUnarFunction = std::map<std::string, double(*)(double)>;

class PluginLoader {
public:

	PluginLoader() { loadDll(); }

    double makeOperation(double const& a, std::string const& funcName, double const& b = 0.0);

    bool containsUnaryFunc(std::string const& funcName) const;

    bool containsBinaryFunc(std::string const& funcName) const;

    mapUnarFunction getUnaryFunction() { return unaryFunctions; };
    mapBinarFunction getBinaryFunction() { return binaryFunctions; };

private:
    std::string pluginsPath = "./plugins/";


    mapUnarFunction unaryFunctions;
    mapBinarFunction binaryFunctions;

    void loadDll();

    void getFunc(std::string const& fileName);

    

};