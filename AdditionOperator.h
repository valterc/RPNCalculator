#pragma once
#include "Operator.h"

template<typename T>
class AdditionOperator :
	public Operator<T>
{
public:
	const T apply(stack<T> &stack);

};

template<typename T>
inline const T AdditionOperator<T>::apply(stack<T> &stack)
{
	if (stack.size() < 2)
	{
		throw InvalidStackStateException("The stack has less then 2 values but two operands were expected by the AdditionOperator.");
	}

	T secondOperand = stack.top();
	stack.pop();

	T firstOperand = stack.top();
	stack.pop();

	T result = firstOperand + secondOperand;
	stack.push(result);

	return result;
}