#include<iostream>
#include<string>
#include<map>

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

private:

	string name = "";
	SymbolType type = SymbolType::undefined;
};