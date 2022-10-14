#pragma once
#include<iostream>
#include"Calculator.hpp"
//#include"Operators.hpp"
//#include"Symbol.hpp"
//#include"ExprHandler.hpp"

class A {
public:
	int a;
};

int main() {
	Calculator calculator;
	//string expr = "((2+3)-6*2) + ((4-2)+(2+3))";
	string expr = "(2*-4)";
	 calculator.calculate(expr);
	//cout << stod(".25");

	//cout << Operators::GetOperators().operation(2, op, 14);;
	//try {}
	//catch{};// expression is correct

	//queue<Symbol> q;
	//Symbol a;
	//a.type = SymbolType::number;
	//a.name = "6";
	//q.push(a);
	//a.type = SymbolType::number;
	//a.name = "2";
	//q.push(a);
	//a.type = SymbolType::number;
	//a.name = "3";
	//q.push(a);
	//a.type = SymbolType::binaryOperator;
	//a.name = "*";
	//q.push(a);
	//a.type = SymbolType::binaryOperator;
	//a.name = "+";
	//q.push(a);
	//a.type = SymbolType::number;
	//a.name = "2";
	//q.push(a);
	//a.type = SymbolType::binaryOperator;
	//a.name = "/";
	//q.push(a);
	//a.type = SymbolType::number;
	//a.name = "1";
	//q.push(a);
	//a.type = SymbolType::binaryOperator;
	//a.name = "+";
	//q.push(a);

	//cout << calculator.countPostNote(q);

	/*while (true) {
		getline(cin, expr);
		if (expr == "" || expr == "exit") {
			return 0;
		}
		calculator.calculate(expr);
	}*/
}