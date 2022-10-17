#include<iostream>
#include<map>
#include<functional>


using mapOperators = std::map<std::string, std::function<double(double, double)>>;

using PriorityMap = std::map<std::string const, int>;

class Operators {
public:

	static Operators& GetOperators();

	int priority(std::string const& operationName);

	double operation(double const& a, std::string const& name, double const& b);

private:
	Operators();

	PriorityMap priorityMap;

	mapOperators operations;
};