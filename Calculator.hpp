#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include"ExprHandler.hpp"
#include"Operators.hpp"
#include<optional>
#include<algorithm>

using namespace std;

class Calculator {
public:
	std::optional<double> calculate(string& expr) {
		Container container;
		ExprHandler handler;
		queue<shared_ptr<Symbol>> postNote;
		try {
			container = handler.splitExpr(expr);
			checkBrackets(container);
			checkOperators(container);
			postNote = toPostNote(container);
		}
		catch (std::exception& e) {
			cout << e.what();
			return nullopt;
		}
		return countPostNote(postNote);
	}

	void checkBrackets(Container const& expr) const {
		stack<shared_ptr<Symbol>> brackets;
		for (auto const& s : expr) {
			if (s->getName() == "(") {
				brackets.push(s);
			}
			if (s->getName() == ")") {
				if (brackets.empty()) {
					throw exception("check your brackets");
					return;
				}
				brackets.pop();
			}
		}
		if (!brackets.empty()) {
			throw exception("check your brackets");
		}
	}

	void checkOperators(Container const& expr) const {
		for (int i = 0; i < expr.size(); ++i) {
			if (i == 0 && 
				(expr[i]->getType() != SymbolType::number && 
				 expr[i]->getType() != SymbolType::unaryOperator &&
				 expr[i]->getType() != SymbolType::openBracket)) {
				throw exception("First symbol can't be a binary operator. Try again");
				return;
			}
			if ( i != expr.size() - 1 && expr[i]->getType() == SymbolType::binaryOperator &&	
				(expr[i - 1]->getType() == SymbolType::binaryOperator ||
				expr[i + 1]->getType() == SymbolType::binaryOperator)) {
				throw exception("wrong expression. Check it and try again");
				return;
			}
			if (i == expr.size() - 1 && expr[i]->getType() == SymbolType::binaryOperator) {
				throw exception("Last symbol can't be a binary operator. Try again");
				return;
			}
		}
	}

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
				while (!stack.empty() && stack.top()->getType() != SymbolType::openBracket ) {
					postfixExpr.push(stack.top());
					stack.pop();
					// проверка что нет открытой скобки
				}
				if (stack.empty()) {
					throw exception("ooops wrong expresion\n Check it and try again");
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