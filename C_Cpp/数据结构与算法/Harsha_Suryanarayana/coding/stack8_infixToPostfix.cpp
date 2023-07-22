/*
Infix to postfix conversion in C++
Input Postfix expression must be in a desired format.
Operands and operator, both must be single character.
Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.
*/
//�ο�������github��https://gist.github.com/mycodeschool/7867739


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
// �β� op1 Ϊ S.top()��op2 Ϊ expression[i]
int HasHigherPrecedence(char op1, char op2);



int main()
{
	// ���ڲ��Եĵ�һ�� Infix ���ӣ�A+B*C-D*E
	// ��������Output = ABC*+DE*-
	// ���ڲ��Եĵڶ��� Infix ���ӣ�A+B*(C-D)/E
	// ��������ABCD-*E/+
	string expression;
	cout << "Please Enter Infix Expression:\n";
	getline(cin, expression);                        // std::getline (string)
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << endl;
}





// Function to convert Infix expression to Postfix expression.
string InfixToPostfix(string expression)
{
	stack<char> S;             // ջ��ŵ��Ǳ��ʽ��Ĳ�����
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
			S.push(expression[i]);    // ��� S.top() == '('��Ҳ��ִ�и����
		}

		//
		else if (expression[i] == '(') S.push(expression[i]);

		// ���� ) ˵��һ�� () �ڵĶ����ġ������ı��ʽ e ���˽�����
		// ��ʱֻҪջ����Ϊ (��˵��ջ���д� top ��ʼ���ĵ�һ�� ( ֮ǰ�Ĳ��������Ǳ��ʽ e �е�
		// ����Ҫ������ pop �����Ž���׺���ʽ�С�
		else if (expression[i] == ')')    
		{
			while (!S.empty() && S.top() != '(') 
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();   // ��ջ���� ( Ҳ��������������
		}

	}

	// Infix ���ʽɨ�����ʱ����Ҫȷ��ջ���Ƿ�Ϊ��
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
// �β� op1 Ϊ S.top()��op2 Ϊ expression[i]
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