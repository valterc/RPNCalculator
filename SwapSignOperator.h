#pragma once
#include "Operator.h"

template<typename T>
class SwapSignOperator :
	public Operator<T>
{
public:
	const T apply(stack<T> &stack);

};

template<typename T>
const T SwapSignOperator<T>::apply(stack<T> &stack)
{
	if (stack.empty())
	{
		throw InvalidStackStateException("The stack is empty but an operand was expected by the SwapSignOperator.");
	}

	T operand = stack.top();
	stack.pop();

	T result = -operand;
	stack.push(result);

	return result;
}