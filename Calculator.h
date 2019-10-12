#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
#include <string>
using namespace std;
enum {
	NONE,
	NUMBER,
	OPERATOR,
	OPEN_PARENTHESE,
	CLOSE_PARENTHESE,
	NOTHING
};
class Calculator
{
private:
	//char buffer[4096] = { 0, };
	string inputString = "";
	string delimiter = " ";
	vector <string> tokens;
public:
	Calculator();
	void getToken()
	{
		tokens.clear();
		size_t pos = 0;
		while ((pos = inputString.find(delimiter)) != string::npos)
		{
			tokens.push_back(inputString.substr(0, pos));
			inputString.erase(0, pos + delimiter.length());
		}
		tokens.push_back(inputString);
		inputString.erase(0, inputString.length());
	}
	int getState(string s)
	{
		int state;
		if ((s.compare("0") >= 0 && s.compare(":") < 0) || (s.compare("-0") >= 0 && s.compare("-:") < 0))
			state = NUMBER;
		else if (s.compare("+") || s.compare("-") || s.compare("*") || s.compare("/"))
			state = OPERATOR;
		else if (s.compare("("))
			state = OPEN_PARENTHESE;
		else if (s.compare(")"))
			state = CLOSE_PARENTHESE;
		else
			state = NOTHING;
		return state;
	}
};
#endif
#pragma once
