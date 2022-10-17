#pragma once
#include<iostream>
#include <sstream>
#include<cstring>
#include<vector>
#include"Symbol.hpp"


using Container = std::vector<std::shared_ptr<Symbol>>;

class ExprHandler {
public:

	ExprHandler() = default;

	Container splitExpr(std::string& expr);

private:
	Container container;

	SymbolType defineType(std::string const& name, int const& symbolPos) const;

	std::string convertCharToString(char const& s) const;

	bool isDigit(char const& s) const;

	bool isLetter(char const& s) const;

	void deleteSpaces(std::string& str);

};