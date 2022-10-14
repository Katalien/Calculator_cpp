#pragma once
#include<iostream>
#include"Calculator.hpp"

int main() {
	Calculator calculator;
	while (true) {
		string expression;
		cout << "Enter your expression:" << endl;
		getline(cin, expression);
		if (expression == "" || expression == "exit") {
			break;
		}
		
		optional<double> res = calculator.calculate(expression);
		cout << "= " << res.value() << std::endl;
	}	
	return 0;
}