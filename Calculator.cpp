#include "Calculator.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


Calculator::Calculator()
{
	cout << "expression : ";
	//fread(buffer, sizeof(char), 20, stdin);
	//inputString = string(buffer);
	getline(cin, inputString);
	getToken();
	int state = NONE;
	BinaryTree<string>*t, *tp, *tr;
	for (vector<int>::size_type i = 0; i < tokens.size(); i++)
	{
		string token = tokens[i];
		int nextState = getState(token);
		BinaryTree<string>* newT = new BinaryTree<string>(token, nextState);
		if (state == NONE)
		{
			if (nextState == NUMBER)
			{
				t = newT;
				tp = newT;
				tr = newT;
			}
			else if (nextState == OPEN_PARENTHESE)
			{

			}
			else
			{
				nextState = NOTHING;
				break;
			}
		}
		else if (state == NUMBER)
		{
			if (nextState == OPERATOR)
			{
				if (t == tp)
				{
					newT->addLeft(tp);
					tp = newT;
				}
				else
				{
					//연산자 우선순위에 따라 달라짐
					newT->addLeft(tp);
					tp = newT;
				}
			}
			else if (nextState == CLOSE_PARENTHESE)
			{
			}
			else
			{
				nextState = NOTHING;
				break;
			}
		}
		else if (state == OPERATOR)
		{
			if (nextState == NUMBER)
			{
				tp->addRight(newT);
			}
			else if (nextState == OPEN_PARENTHESE)
			{
			}
			else
			{
				nextState = NOTHING;
				break;
			}
		}
		else if (state == OPEN_PARENTHESE)
		{
			if (nextState == NUMBER)
			{
			}
			else
			{
				nextState = NOTHING;
				break;
			}
		}
		else if (state == CLOSE_PARENTHESE)
		{
			if (nextState == OPEN_PARENTHESE)
			{
			}
			else
			{
				nextState = NOTHING;
				break;
			}
		}
		state = nextState;
		t = newT;
	}
	tp->printInOrder();
}