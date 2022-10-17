#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include"ExprHandler.hpp"
#include"Operators.hpp"
#include"PluginLoader.hpp"
#include<optional>
#include<algorithm>

using PostNoteQueue = std::queue<std::shared_ptr<Symbol>>;

class Calculator {
public:

	Calculator() = default;

	std::optional<double> calculate(std::string& expr);

private:

	std::optional<double> countPostNote(PostNoteQueue& postfixExpr);

	void checkBrackets(Container const& expr) const;

	void checkOperators(Container const& expr) const;

	PostNoteQueue toPostNote(Container const& container);

	void manageBaseOperator(PostNoteQueue& postfixExpr, std::stack<double>& stack, std::shared_ptr<Symbol> const& curSymbol);
	
	void manageFunction(PostNoteQueue& postfixExpr, std::stack<double>& stack, std::shared_ptr<Symbol> const& curSymbol);

};