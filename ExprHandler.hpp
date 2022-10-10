#include<iostream>
#include<vector>
#include"Symbol.hpp"

using namespace std;

using Container = vector<shared_ptr<Symbol>>;

class ExprHandler {
public:
	
	ExprHandler() = default;

	 Container splitExpr(string expr){
		///
		 return container;
	 };

private:
	Container container;
};