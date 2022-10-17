#include"Operators.hpp"

Operators::Operators() {
	operations["+"] = [](double a, double b)->double {return a + b;};
	operations["-"] = [](double a, double b)->double {return b - a;};
	operations["*"] = [](double a, double b)->double {return a * b;};
	operations["/"] = [](double a, double b)->double {return b / a;};
	operations["--"] = [](double a, double b)->double {return 0 - a;};
	operations["^"] = [](double a, double b) {return powl(b, a);};

	priorityMap["("] = 0;
	priorityMap["+"] = 1;
	priorityMap["-"] = 1;
	priorityMap["*"] = 2;
	priorityMap["/"] = 2;
	priorityMap["--"] = 3;
	priorityMap["^"] = 4;
};

Operators& Operators::GetOperators() {
	static Operators instance;
	return instance;
};

int Operators::priority(std::string const& operationName) {
	return priorityMap[operationName];
}

double Operators::operation(double const& a, std::string const& name, double const& b) {
	return operations[name](a, b);
};
