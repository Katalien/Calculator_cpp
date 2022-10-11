#include<iostream>
#include<string>

using namespace std;

enum class SymbolType {
		number,
		function,
		unaryOperator,
		binaryOperator,
		closeBracket,
		openBracket,
		undefined
	};

class Symbol {
public:
	
	string getName() { return name; };
	SymbolType getType() { return type; ; };
	void setName(string& _name) { name = _name; };
	void setType(SymbolType _type) { type = _type; };

	void setType(string& _name, char const& prev, int const& symbolPos) {
		if (name == "") {
			name = _name;
		}
		if (name == "+" || name == "*" || name == "/") {
			type = SymbolType::binaryOperator;
		}
		if (name == "-") {
			if (symbolPos == 0 || (symbolPos != 0 && prev == '(') && prev != ')') {
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
	}

private:

	string name = "";
	SymbolType type = SymbolType::undefined;
};