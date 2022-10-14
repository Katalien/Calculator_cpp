#include"ExprHandler.hpp"

Container ExprHandler::splitExpr(string& expr) {
	deleteSpaces(expr);
	int pos = 0;
	stringstream ss;
	string curStr, numStr;
	for (int i = 0; i < expr.size(); ++i) {
		char s = expr[i];
		if (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')') {
			shared_ptr<Symbol> symbol = make_shared<Symbol>();
			curStr = convertCharToString(s);
			symbol->setName(curStr);
			if (s == '-' && ((i == 0) || (i != 0 && (!isDigit(expr[i - 1]) && expr[i - 1] != ')' || expr[i - 1] == '(')))) {
				string unarName = "--";
				symbol->setName(unarName);
				symbol->setType(SymbolType::unaryOperator);
			}
			else {
				symbol->setType(defineType(curStr, i));
			}
			container.push_back(symbol);
		}
		else if (isDigit(expr[i])) {
			while (isDigit(expr[i])) {
				numStr += convertCharToString(expr[i]);
				i++;
			}
			shared_ptr<Symbol> numSymbol = make_shared<Symbol>();
			numSymbol->setName(numStr);
			numSymbol->setType(SymbolType::number);
			container.push_back(numSymbol);
			i--;
			numStr = "";
		}
		else {
			throw exception("wrong symbols. Check your expression and try again");
		}
	}
	return container;
}

SymbolType ExprHandler::defineType(string const& name, int const& symbolPos) const {
	SymbolType type = SymbolType::undefined;
	if (name == "+" || name == "*" || name == "/") {
		type = SymbolType::binaryOperator;
	}
	if (name == "-") {
		type = SymbolType::binaryOperator;
	}
	if (name == "(") {
		type = SymbolType::openBracket;
	}
	if (name == ")") {
		type = SymbolType::closeBracket;
	}
	return type;
}

string ExprHandler::convertCharToString(char const& s) const {
	stringstream ss;
	string str;
	ss << s;
	ss >> str;
	return str;
}

bool ExprHandler::isDigit(char const& s) const {
	if ((s >= '0' && s <= '9') || s == '.') {
		return true;
	}
	else {
		return false;
	}
}

void ExprHandler::deleteSpaces(string& str) {
	while (str.find(' ') != string::npos) {
		str.erase(str.find(' '), 1);
	}
};