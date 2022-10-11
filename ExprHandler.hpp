#pragma once
#include<iostream>
#include <sstream>
#include<cstring>
#include<vector>
#include"Symbol.hpp"

using namespace std;

using Container = vector<shared_ptr<Symbol>>;

class ExprHandler {
public:

	ExprHandler() = default;

	Container splitExpr(string& expr) {
		deleteSpaces(expr);
		cout << expr << endl;
		int pos = 0;
		stringstream ss;
		string curStr, numStr;
		for (int i = 0; i < expr.size(); ++i) {
			char s = expr[i];
			if (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')') {
				shared_ptr<Symbol> symbol = make_shared<Symbol>();
				curStr = convertCharToString(s);
				symbol->setName(curStr);
				if (i == 0 && s == '-') {
					symbol->setType(SymbolType::unaryOperator);
				}
				else {
					symbol->setType(defineType(curStr, expr[i - 1], i));
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
		}
		return container;
	}

	SymbolType defineType(string& name, char const& prev, int const& symbolPos) {
		SymbolType type;
		if (name == "+" || name == "*" || name == "/") {
			type = SymbolType::binaryOperator;
		}
		if (name == "-") {
			if ( !isDigit(prev) && prev!='(') {
				type = SymbolType::unaryOperator;
				name = '--';
			}
			else {
				type = SymbolType::binaryOperator;
			}
		}
		if (name == "(") {
			type = SymbolType::openBracket;
		}
		if (name == ")") {
			type = SymbolType::closeBracket;
		}
		return type;
	}

	string convertCharToString(char& s) {
		stringstream ss;
		string str;
		ss << s;
		ss >> str;
		return str;
	}

	bool isDigit(char s) {
		if ((s >= '0' && s <= '9') || s == '.') {
			return true;
		}
		else {
			return false;
		}
	}

	 void deleteSpaces(string& str) {
		 while (str.find(' ') != string::npos) {
			 str.erase(str.find(' '), 1);
		 }
	 };

private:
	Container container;
};