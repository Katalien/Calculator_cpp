#include<iostream>
#include"Calculator.hpp"
//#include"Symbol.hpp"

int main() {
	Calculator calculator;
	string expr = "";

	queue<Symbol> q;
	Symbol a;
	a.type = SymbolType::number;
	a.name = "100";
	q.push(a);
	a.type = SymbolType::number;
	a.name = "2";
	q.push(a);
	a.type = SymbolType::binaryOperator;
	a.name = "divide";
	q.push(a);
	a.type = SymbolType::number;
	a.name = "2";
	q.push(a);
	a.type = SymbolType::binaryOperator;
	a.name = "divide";
	q.push(a);
	a.type = SymbolType::number;
	a.name = "2";
	q.push(a);
	a.type = SymbolType::binaryOperator;
	a.name = "divide";
	q.push(a);
	a.type = SymbolType::number;
	a.name = "2";
	q.push(a);
	a.type = SymbolType::binaryOperator;
	a.name = "divide";
	q.push(a);

	cout << calculator.countPostNote(q);

	/*while (true) {
		getline(cin, expr);
		if (expr == "" || expr == "exit") {
			return 0;
		}
		calculator.calculate(expr);
	}*/
}