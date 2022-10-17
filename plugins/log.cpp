#include <cmath>

extern "C" __declspec(dllexport)
double binaryFunction(double x, double y) {
    return log(x)/log(y);
}
