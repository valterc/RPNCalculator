#pragma once
#include "Operator.h"
#include <string>

template<typename T>
class TwoOperandOperator :
	public Operator<T>
{
public:
	const T apply(std::stack<T> &stack);
	virtual const T apply(const T &firstOperand, const T &secondOperand, std::stack<T> &stack) = 0;
};

template<typename T>
const T TwoOperandOperator<T>::apply(std::stack<T> &stack)
{
	if (stack.size() < 2)
	{
		std::ostringstream strstream;
		strstream << "The stack has less than 2 values but two operands were expected by ";
		strstream << typeid(this).name();

		throw InvalidStackStateException(strstream.str().c_str());
	}

	T secondOperand = stack.top();
	stack.pop();

	T firstOperand = stack.top();
	stack.pop();

	return apply(firstOperand, secondOperand, stack);
}