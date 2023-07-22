/*
Evaluation Of postfix Expression in C++
Input Postfix expression must be in a desired format.
Operands must be integers and there should be space in between two operands.
Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/
//参考引用自github：https://gist.github.com/mycodeschool/7702441

#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression);

// Function to perform an operation and return output
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not
bool IsOperator(char C);

// Function to verify whether a character is numeric digit
bool IsNumericDigit(char C);





int main() 
{
	// 用于测试的一个 Postfix 例子：2 3 * 5 4 * + 9 -
	// 输出结果：Output = 17
	string expression;
	cout << "Please Enter Postfix Expression:\n";
	getline(cin, expression);                           // std::getline (string)
	int result = EvaluatePostfix(expression);
	cout << "Output = " << result << endl;
}





// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression)
{
	stack<int> S;     // 栈存放的是表达式里的操作数(这里限定操作数都是整数)

	for (int i = 0; i < expression.length(); i++)
	{
		// If character is delimitter, move on.
		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if (IsOperator(expression[i]))
		{
			int operand2 = S.top(); S.pop();     // 这里要注意，S.top() 要先赋值给操作数2，否则对于减法和除法会出错
			int operand1 = S.top(); S.pop();

			int result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);
		}

		else if (IsNumericDigit(expression[i]))
		{
			// Extract the numeric operand from the string expression.
			// And keep incrementing i as long as we are getting a numeric digit.
			int operand = 0;
			while (i < expression.length() && IsNumericDigit(expression[i]))
			{
				// For a number with more than one digits
				// As we are scanning from left to right, everytime, we get a digit towards right.
				// We can multiply current total in operand by 10 and add the new digit. 
				operand = operand * 10 + (expression[i] - '0');
				i++;
			}

			S.push(operand);

			// Finally, we will come out of while loop with i set to a non-numeric character or end of string.
			// So decrement i because it will be incremented in increment section of for loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice.
			// 因为 跳出 while 循环时的上一句是 i++，并且当前 for 循环的最后一句将会执行 i++,会导致重复执行
			i--;
		}

	}// for 循环结束

	// If expression is in correct format, Stack will finally have one element. This will be the output. 
	return S.top();
}


// Function to perform an operation and return output
int PerformOperation(char operation, int operand1, int operand2)
{
	if (operation == '+') return operand1 + operand2;
	else if (operation == '-') return operand1 - operand2;
	else if (operation == '*') return operand1 * operand2;
	else if (operation == '/') return operand1 / operand2;

	else cout << "Unexpected Error!\n";
	return -1;
}


// Function to verify whether a character is operator symbol or not
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/') return true;
	return false;
}


// Function to verify whether a character is numeric digit
bool IsNumericDigit(char C)
{
	if (C >= '0' && C <= '9') return true;
	return false;
}