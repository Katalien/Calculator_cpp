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

	Container splitExpr(string& expr);

private:
	Container container;

	SymbolType defineType(string const& name, int const& symbolPos) const;

	string convertCharToString(char const& s) const;

	bool isDigit(char const& s) const;

	void deleteSpaces(string& str);

};