#include<iostream>
#include<string>

using namespace std;

enum class SymbolType {
	number,
	function,
	unaryOperator,
	binaryOperator,
	closeBracket,
	openBracket
};

class Symbol {
public:
	
	string getName() { return name; };
	SymbolType getType() { return type; ; };

//private:

	string name = "";
	SymbolType type;
};