#include"Calculator.hpp"

std::optional<double> Calculator::calculate(std::string& expr) {
	Container container;
	ExprHandler handler;
	PostNoteQueue postNote;
	try {
		container = handler.splitExpr(expr);
		checkBrackets(container);
		checkOperators(container);
		postNote = toPostNote(container);
	}
	catch (std::exception& e) {
		std::cout << e.what();
		return std::nullopt;
	}
	return countPostNote(postNote);
}

PostNoteQueue Calculator::toPostNote(Container const& container) {
	std::stack<std::shared_ptr<Symbol>> stack;
	PostNoteQueue postfixExpr;
	for (auto& s : container) {
		if (s->getType() == SymbolType::number) {
			postfixExpr.push(s);
			continue;
		}
		//check that symbol is base operator
		if (s->getType() == SymbolType::binaryOperator || s->getType() == SymbolType::unaryOperator) {
			int curPriority = Operators::GetOperators().priority(s->getName());
			if (stack.size() != 0) {
				while (!stack.empty() && (Operators::GetOperators().priority(stack.top()->getName()) >= curPriority || stack.top()->getType() == SymbolType::function)) {
					postfixExpr.push(stack.top());
					stack.pop();
				}
			}
			stack.push(s);
			continue;
		}
		//check if symbol is function
		if (s->getType() == SymbolType::function) {
			int curPriority = 6;
			while (!stack.empty() && stack.top()->getType() == SymbolType::function) {
				postfixExpr.push(stack.top());
				stack.pop();
			}
			stack.push(s);
			continue;
		}
		if (s->getType() == SymbolType::openBracket) {
			stack.push(s);
			continue;
		}
		if (s->getType() == SymbolType::closeBracket) {
			while (!stack.empty() && stack.top()->getType() != SymbolType::openBracket) {
				postfixExpr.push(stack.top());
				stack.pop();
			}
			if (stack.empty()) {
				throw std::exception("ooops wrong expresion\n Check it and try again");
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


std::optional<double> Calculator::countPostNote(PostNoteQueue& postfixExpr) {
	std::stack<double> stack;
	while (!postfixExpr.empty()) {
		std::shared_ptr<Symbol> curSymbol = postfixExpr.front();
		if (curSymbol->getType() == SymbolType::number) {
			stack.push(stod(postfixExpr.front()->getName()));
			postfixExpr.pop();
			continue;
		}

		if ((curSymbol->getType() == SymbolType::function)) {
			try {
				manageFunction(postfixExpr, stack, curSymbol);
			}
			catch (std::exception& e) {
				std::cout << e.what();
				return std::nullopt;
			}
			continue;
		}

		if (curSymbol->getType() == SymbolType::binaryOperator || curSymbol->getType() == SymbolType::unaryOperator) {
			manageBaseOperator(postfixExpr, stack, curSymbol);
			continue;
		}
	}
	return stack.top();
}

void Calculator::manageFunction(PostNoteQueue& postfixExpr, std::stack<double>& stack, std::shared_ptr<Symbol> const& curSymbol) {
	double a = stack.top();
	double b = 0.0;
	stack.pop();
	PluginLoader func;
	if (func.containsBinaryFunc(curSymbol->getName())) {
		b = stack.top();
		stack.pop();
	}
	if (!func.containsUnaryFunc(curSymbol->getName()) && !func.containsBinaryFunc(curSymbol->getName())) {
		throw std::exception("no such function");
		return;
	}
	double res = func.makeOperation(a, curSymbol->getName(), b);
	stack.push(res);
	postfixExpr.pop();
}

void Calculator::manageBaseOperator(PostNoteQueue& postfixExpr, std::stack<double>& stack, std::shared_ptr<Symbol> const& curSymbol) {
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
}



void Calculator::checkBrackets(Container const& expr) const {
	std::stack<std::shared_ptr<Symbol>> brackets;
	for (auto const& s : expr) {
		if (s->getName() == "(") {
			brackets.push(s);
		}
		if (s->getName() == ")") {
			if (brackets.empty()) {
				throw std::exception("check your brackets");
				return;
			}
			brackets.pop();
		}
	}
	if (!brackets.empty()) {
		throw std::exception("check your brackets");
	}
}

void Calculator::checkOperators(Container const& expr) const {
	for (int i = 0; i < expr.size(); ++i) {
		if (i == 0 &&
			(expr[i]->getType() != SymbolType::number &&
			expr[i]->getType() != SymbolType::function &&
				expr[i]->getType() != SymbolType::unaryOperator &&
				expr[i]->getType() != SymbolType::openBracket)) {
			throw std::exception("wrong expression. Check it and try again");
			return;
		}
		if (i != expr.size() - 1 && expr[i]->getType() == SymbolType::binaryOperator &&
			(expr[i - 1]->getType() == SymbolType::binaryOperator ||
				expr[i + 1]->getType() == SymbolType::binaryOperator)) {
			throw std::exception("wrong expression. Check it and try again");
			return;
		}
		if (i == expr.size() - 1 && expr[i]->getType() == SymbolType::binaryOperator) {
			throw std::exception("wrong expression. Check it and try again");
			return;
		}
	}
}

