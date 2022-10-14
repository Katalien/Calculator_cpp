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

	Calculator() = default;

	optional<double> calculate(string& expr);

private:

	double countPostNote(queue<shared_ptr<Symbol>>& postfixExpr);

	void checkBrackets(Container const& expr) const;

	void checkOperators(Container const& expr) const;

	queue<shared_ptr<Symbol>> toPostNote(Container const& container);


};