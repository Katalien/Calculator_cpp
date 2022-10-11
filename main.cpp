#pragma once
#include<iostream>
#include"Calculator.hpp"
//#include"Operators.hpp"
//#include"Symbol.hpp"
//#include"ExprHandler.hpp"


int main() {
	//Calculator calculator;
	//string expr = "";
	//string op = "/";
	//string s = "a aa aaa Ba aa aa aa";
	//deleteSpaces(s);
	//cout << s;
	
	string str = "-1 + 32*(2/2)*-1";
	ExprHandler handler;
	handler.splitExpr(str);

	
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