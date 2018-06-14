#pragma once

#include <ostream>
#include "Operator.h"

template<typename T>
class PrintStackTopOperator :
	public Operator<T>
{
private:
	ostream & stream;

public:
	PrintStackTopOperator(ostream &stream);
	const T apply(stack<T> &stack);
};

template<typename T>
inline PrintStackTopOperator<T>::PrintStackTopOperator(ostream &stream) : stream(stream)
{
}

template<typename T>
inline const T PrintStackTopOperator<T>::apply(stack<T> &stack)
{
	if (stack.empty())
	{
		throw InvalidStackStateException("The stack is empty but an operand was expected by the PrintStackOperator.");
	}

	T operand = stack.top();

	stream << operand;

	return operand;
}
