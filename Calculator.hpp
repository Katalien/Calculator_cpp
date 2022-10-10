#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include"ExprHandler.hpp"

using namespace std;

class Calculator {
public:
	double calculate(string const& expr) {
		ExprHandler handler;
		Container container = handler.splitExpr(expr);
		queue<Symbol> postNote = toPostNote(container);

	}

	queue<Symbol> toPostNote(Container container) {
		// take parsed expr and create a queue in postfix notation
	}

	double makeBinaryCalculation(double a, Symbol operation, double b) {
		if (operation.getName() == "add") {
			return a + b;
		}
		if (operation.getName() == "substruct") {
			return b - a;
		}
		if (operation.getName() == "multiply") {
			return a * b;
		}
		if (operation.getName() == "divide") {
			return b / a;
		}
	}

	double makeUnaryCalculation(double a) {
		return 0.0 - a;
	}

	void print(stack<double> stack) {
		for (int i = 0; i < stack.size(); ++i) {
			cout << stack.top() << " ";
			stack.pop();
		}
		cout << endl;
	}

	// 7 2 3 * -
	double countPostNote(queue<Symbol>& postfixExpr) {
		//take postfix notation and count the result
		stack<double> stack;
		while (!postfixExpr.empty()) {
			Symbol curSymbol = postfixExpr.front();
			if (curSymbol.getType() == SymbolType::number) {
				stack.push(stod(postfixExpr.front().getName()));
				postfixExpr.pop();
				continue;
			}
			if (curSymbol.getType() == SymbolType::binaryOperator) {
				double a = stack.top();
				stack.pop();
				double b = stack.top();
				stack.pop();
				double res = makeBinaryCalculation(a, curSymbol, b);
				stack.push(res);
				postfixExpr.pop();
				continue;
			}
			if (curSymbol.getType() == SymbolType::unaryOperator) {
				double a = stack.top();
				stack.pop();
				double res = makeUnaryCalculation(a);
				stack.push(res);
				continue;
			}
		}
		return stack.top();
	}

private:
	

};