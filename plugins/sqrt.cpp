#include <cmath>

extern "C" __declspec(dllexport)
double unaryFunction(double x) {
    return sqrt(x);
}
