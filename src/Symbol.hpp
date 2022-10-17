#include<iostream>
#include<string>
#include<map>


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
	std::string getName() { return name; };

	SymbolType getType() { return type; ; };

	void setName(std::string& _name) { name = _name; };

	void setType(SymbolType _type) { type = _type; };

private:
	std::string name = "";

	SymbolType type = SymbolType::undefined;
};