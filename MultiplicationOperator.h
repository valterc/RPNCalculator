#pragma once
#include "Operator.h"

template<typename T>
class MultiplicationOperator :
	public Operator<T>
{
public:
	const T apply(stack<T> &stack);

};

template<typename T>
const T MultiplicationOperator<T>::apply(stack<T> &stack)
{
	if (stack.size() < 2)
	{
		throw InvalidStackStateException("The stack has less then 2 values but two operands were expected by the MultiplicationOperator.");
	}

	T secondOperand = stack.top();
	stack.pop();

	T firstOperand = stack.top();
	stack.pop();

	T result = firstOperand * secondOperand;
	stack.push(result);

	return result;
}