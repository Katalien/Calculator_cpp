#include<iostream>
#include<map>
#include<functional>

using namespace std;

using mapOperators = map<string, function<double(double, double)>>;

using PriorityMap = map<string const, int>;

class Operators {
public:

	static Operators& GetOperators();

	int priority(string const& operationName);

	double operation(double const& a, string const& name, double const& b);

private:
	Operators();

	PriorityMap priorityMap;

	mapOperators operations;
};