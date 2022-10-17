#pragma once
#include<iostream>
#include"Calculator.hpp"


int main() {
	Calculator calculator;
	while (true) {
		std::string expression;
		std::cout << "Enter your expression or press Enter to exit:" << std::endl;
		std::getline(std::cin, expression);
		if (expression == "" || expression == "exit") {
			break;
		}
		
		std::optional<double> res = calculator.calculate(expression);
		if (res.has_value()) {
			std::cout << "= " << res.value() << std::endl;
		}
	}	
	return 0;
}

