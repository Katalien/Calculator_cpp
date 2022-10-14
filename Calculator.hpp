#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include"ExprHandler.hpp"
#include"Operators.hpp"

using namespace std;

class Calculator {
public:
	double calculate(string& expr) {
		ExprHandler handler;
		Container container = handler.splitExpr(expr);
		try { 
			checkValidity(container);
		}
		catch (exception e) {
		//
		};
		queue<shared_ptr<Symbol>> postNote = toPostNote(container);
		return countPostNote(postNote);
	}

	void checkValidity(Container container) {
	};

// take parsed expr and create a queue in postfix notation
	queue<shared_ptr<Symbol>> toPostNote(Container const& container) {
		stack<shared_ptr<Symbol>> stack;
		queue<shared_ptr<Symbol>> postfixExpr;
		for (auto& s : container) {
			if (s->getType() == SymbolType::number) {
				postfixExpr.push(s);
				continue;
			}
			//проверка что символ- оператор
			if (s->getType() == SymbolType::binaryOperator || s->getType() == SymbolType::unaryOperator) {
				int curPriority = Operators::GetOperators().priority(s->getName());
				if (stack.size() != 0) {
					while (!stack.empty() && Operators::GetOperators().priority(stack.top()->getName()) >= curPriority ) {
						postfixExpr.push(stack.top());
						stack.pop();
					}
				}
				stack.push(s);
				continue;
			}
			if (s->getType() == SymbolType::openBracket) {
				stack.push(s);
				continue;
			}
			if (s->getType() == SymbolType::closeBracket) {
				while (stack.top()->getType() != SymbolType::openBracket && !stack.empty()) {
					postfixExpr.push(stack.top());
					stack.pop();
					// проверка что нет открытой скобки
				}
				stack.pop();
			}
		}
		while (!stack.empty()) {
			postfixExpr.push(stack.top());
			stack.pop();
		}
		return postfixExpr;
	}

	void print(queue<shared_ptr<Symbol>> cont) {
		for (int i = 0; i < cont.size(); ++i) {
			cout << cont.front()->getName() << " ";
			cont.pop();
		}
		cout << endl;
	}

private:
	//take container with elements in postfix notation and count the result
	double countPostNote(queue<shared_ptr<Symbol>>& postfixExpr) {
		stack<double> stack;
		while (!postfixExpr.empty()) {
			shared_ptr<Symbol> curSymbol = postfixExpr.front();
			if (curSymbol->getType() == SymbolType::number) {
				stack.push(stod(postfixExpr.front()->getName()));
				postfixExpr.pop();
				continue;
			}
			if (curSymbol->getType() == SymbolType::binaryOperator || curSymbol->getType() == SymbolType::unaryOperator) {
				double a = stack.top();
				double b = 0.0;
				stack.pop();
				if (curSymbol->getType() == SymbolType::binaryOperator) {
					b = stack.top();
					stack.pop();
				}
				double res = Operators::GetOperators().operation(a, curSymbol->getName(), b);
				stack.push(res);
				postfixExpr.pop();
				continue;
			}
		}
		return stack.top();
	}

};