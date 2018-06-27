#pragma once
#include "Operator.h"
#include <string>

template<typename T>
class SingleOperandOperator :
	public Operator<T>
{
public:
	const T apply(std::stack<T> &stack);
	virtual const T apply(const T &operand, std::stack<T> &stack) = 0;
};

template<typename T>
const T SingleOperandOperator<T>::apply(std::stack<T> &stack)
{
	if (stack.empty())
	{
		std::ostringstream strstream;
		strstream << "The stack is empty but an operand was expected by ";
		strstream << typeid(this).name();

		throw InvalidStackStateException(strstream.str().c_str());
	}

	T operand = stack.top();
	return apply(operand, stack);
}