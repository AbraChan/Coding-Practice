/*
Infix to postfix conversion in C++
Input Postfix expression must be in a desired format.
Operands and operator, both must be single character.
Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.
*/
//参考引用自github：https://gist.github.com/mycodeschool/7867739


#include<iostream>
#include<string>
#include<stack>

using namespace std;

// Function to convert Infix expression to Postfix expression.
string InfixToPostfix(string expression);

// Function to verify whether an charactor is alpha-numeric charactor (letter or numeric digit) or not.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C);

// Function to verify whether an charactor is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op);

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op);

// Function to verify whether an operator has higer precedence over others.
// 形参 op1 为 S.top()，op2 为 expression[i]
int HasHigherPrecedence(char op1, char op2);



int main()
{
	// 用于测试的第一个 Infix 例子：A+B*C-D*E
	// 输出结果：Output = ABC*+DE*-
	// 用于测试的第二个 Infix 例子：A+B*(C-D)/E
	// 输出结果：ABCD-*E/+
	string expression;
	cout << "Please Enter Infix Expression:\n";
	getline(cin, expression);                        // std::getline (string)
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << endl;
}





// Function to convert Infix expression to Postfix expression.
string InfixToPostfix(string expression)
{
	stack<char> S;             // 栈存放的是表达式里的操作符
	string postfix = "";

	for (int i = 0; i < expression.length(); i++)
	{
		// Scanning each character from left. If character is a delimitter, move on.
		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operand
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		// If character is operator
		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);    // 如果 S.top() == '('，也会执行该语句
		}

		//
		else if (expression[i] == '(') S.push(expression[i]);

		// 遇到 ) 说明一对 () 内的独立的、完整的表达式 e 到此结束。
		// 此时只要栈顶不为 (，说明栈内中从 top 开始数的第一个 ( 之前的操作符都是表达式 e 中的
		// 都需要被连续 pop 出来放进后缀表达式中。
		else if (expression[i] == ')')    
		{
			while (!S.empty() && S.top() != '(') 
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();   // 把栈顶的 ( 也弹出，但舍弃掉
		}

	}

	// Infix 表达式扫描结束时，还要确认栈内是否为空
	while (!S.empty())
	{
		postfix += S.top();
		S.pop();
	}

	return postfix;
}


// Function to verify whether an charactor is alpha-numeric charactor (letter or numeric digit) or not.
// We are assuming in this solution that operand will be a single character.
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}


// Function to verify whether an charactor is operator symbol or not.
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$') return true;
	return false;
}


// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}


// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+': weight = 1; break;
	case '-': weight = 1; break;
	case '*': weight = 2; break;
	case '/': weight = 2; break;
	case '$': weight = 3; break;
	}

	return weight;
}


// Function to verify whether an operator has higer precedence over others.
// 形参 op1 为 S.top()，op2 为 expression[i]
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence:
	//     * return true, if they are left associative
	//     * return false, if right associative
	// If operator is left-associative, left one should be given priority.
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}

	return op1Weight > op2Weight ? true : false;
}