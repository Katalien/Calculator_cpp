#include<iostream>
#include<map>
#include<functional>

using namespace std;

using mapOperators = map<string, function<double(double, double)>>;

using PriorityMap = map<string const, int>;

class Operators {
public:
	static Operators& GetOperators() {
		static Operators instance;
		return instance;
	};

	int priority(string const& operationName) {
		return priorityMap[operationName];
	}

	double operation(double a, string name, double b) {
		return operations[name](a, b);
	};

private:
	Operators() {
		operations["+"] = [](double a, double b)->double {return a + b;};
		operations["-"] = [](double a, double b)->double {return b - a;};
		operations["*"] = [](double a, double b)->double {return a * b;};
		operations["/"] = [](double a, double b)->double {return b / a;};
		operations["--"] = [](double a, double b)->double {return 0-a;};

		priorityMap["("] = 0;
		priorityMap["+"] = 1;
		priorityMap["-"] = 1;
		priorityMap["*"] = 2;
		priorityMap["/"] = 2;
		priorityMap["--"] = 3;
	};


	PriorityMap priorityMap;
	mapOperators operations;
};