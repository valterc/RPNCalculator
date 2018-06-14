#pragma once

#include <ostream>
#include "SingleOperandOperator.h"

template<typename T>
class PrintStackTopOperator :
	public SingleOperandOperator<T>
{
private:
	ostream & stream;

public:
	PrintStackTopOperator(ostream &stream);
	const T apply(const T &operand, stack<T> &stack);
};

template<typename T>
inline PrintStackTopOperator<T>::PrintStackTopOperator(ostream &stream) : stream(stream)
{
}

template<typename T>
inline const T PrintStackTopOperator<T>::apply(const T &operand, stack<T> &stack)
{
	stream << operand;
	return operand;
}
