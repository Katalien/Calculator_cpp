#include<iostream>
#include<map>
#include<functional>

using namespace std;

using mapOperators = map<string, function<double(double, double)>>;

class Operators {
public:
	static Operators& GetOperators() {
		static Operators instance;
		return instance;
	};

	double operation(double a, string name, double b = 0.0) {
		return operations[name](a, b);
	};

private:
	Operators() {
		operations["+"] = [](double a, double b)->double {return a + b;};
		operations["-"] = [](double a, double b)->double {return b - a;};
		operations["*"] = [](double a, double b)->double {return a * b;};
		operations["/"] = [](double a, double b)->double {return b / a;};
	};

	mapOperators operations;
};