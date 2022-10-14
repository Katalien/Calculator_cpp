#include"Operators.hpp"

Operators::Operators() {
	operations["+"] = [](double a, double b)->double {return a + b;};
	operations["-"] = [](double a, double b)->double {return b - a;};
	operations["*"] = [](double a, double b)->double {return a * b;};
	operations["/"] = [](double a, double b)->double {return b / a;};
	operations["--"] = [](double a, double b)->double {return 0 - a;};

	priorityMap["("] = 0;
	priorityMap["+"] = 1;
	priorityMap["-"] = 1;
	priorityMap["*"] = 2;
	priorityMap["/"] = 2;
	priorityMap["--"] = 3;
};

Operators& Operators::GetOperators() {
	static Operators instance;
	return instance;
};

int Operators::priority(string const& operationName) {
	return priorityMap[operationName];
}

double Operators::operation(double const& a, string const& name, double const& b) {
	return operations[name](a, b);
};
