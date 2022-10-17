#include"ExprHandler.hpp"

Container ExprHandler::splitExpr(std::string& expr) {
	deleteSpaces(expr);
	int pos = 0;
	std::stringstream ss;
	std::string curStr, numStr;
	for (int i = 0; i < expr.size(); ++i) {
		char s = expr[i];
		if (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')' || s == '^') {
			std::shared_ptr<Symbol> symbol = std::make_shared<Symbol>();
			curStr = convertCharToString(s);
			symbol->setName(curStr);
			if (s == '-' && ((i == 0) || (i != 0 && (!isDigit(expr[i - 1]) && expr[i - 1] != ')' || expr[i - 1] == '(')))) {
				std::string unarName = "--";
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
			std::shared_ptr<Symbol> numSymbol = std::make_shared<Symbol>();
			numSymbol->setName(numStr);
			numSymbol->setType(SymbolType::number);
			container.push_back(numSymbol);
			i--;
			numStr = "";
		}
		///
		else if(isalpha(expr[i])) {
			while (isalpha(expr[i])) {
				numStr += convertCharToString(expr[i]);
				i++;
			}
			std::shared_ptr<Symbol> numSymbol = std::make_shared<Symbol>();
			numSymbol->setName(numStr);
			numSymbol->setType(SymbolType::function);
			container.push_back(numSymbol);
			i--;
			numStr = "";
		}
	}
	return container;
}

SymbolType ExprHandler::defineType(std::string const& name, int const& symbolPos) const {
	SymbolType type = SymbolType::undefined;
	if (name == "+" || name == "*" || name == "/" || name == "^") {
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

std::string ExprHandler::convertCharToString(char const& s) const {
	std::stringstream ss;
	std::string str;
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

bool ExprHandler::isLetter(char const& s) const {
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
		return true;
	}
	else {
		return false;
	}
}

void ExprHandler::deleteSpaces(std::string& str) {
	while (str.find(' ') != std::string::npos) {
		str.erase(str.find(' '), 1);
	}
};