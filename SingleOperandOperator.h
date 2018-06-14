#pragma once
#include "Operator.h"
#include <string>

template<typename T>
class SingleOperandOperator :
	public Operator<T>
{
public:
	const T apply(stack<T> &stack);
	virtual const T apply(const T &operand, stack<T> &stack) = 0;
};

template<typename T>
const T SingleOperandOperator<T>::apply(stack<T> &stack)
{
	if (stack.empty())
	{
		ostringstream strstream;
		strstream << "The stack is empty but an operand was expected by ";
		strstream << typeid(this).name();

		throw InvalidStackStateException(strstream.str().c_str());
	}

	T operand = stack.top();
	return apply(operand, stack);
}