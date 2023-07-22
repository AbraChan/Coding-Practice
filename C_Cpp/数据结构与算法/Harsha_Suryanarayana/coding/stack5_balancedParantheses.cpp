/*
C++ Program to check for balanced parentheses in an expression using stack.
Given an expression as string comprising of opening and closing characters
of parentheses - (), curly braces - {} and square brackets - [], we need to
check whether symbols are balanced or not.
*/
//参考引用自github：https://gist.github.com/mycodeschool/7207410


#include<iostream>
#include<stack>
#include<string>

using namespace std;

//Function to check whether two characters are opening and closing of same type.
bool ArePair(char opening, char closing) 
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}


bool AreParenthesesBalanced(string exp)
{
	stack<char> S;
	for (int i = 0; i < exp.length(); i++) 
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			S.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i])) return false;
			else S.pop();
		}
	}
	return S.empty() ? true : false;
}



int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout << "Please enter an expression: ";    //Input expression from STDIN/Console
	cin >> expression;
	if (AreParenthesesBalanced(expression))
	{
		cout << "Balanced" << endl;
	}
	else
		cout << "Not Balanced\n";

}