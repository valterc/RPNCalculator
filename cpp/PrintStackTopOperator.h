#pragma once

#include <ostream>
#include "SingleOperandOperator.h"

template<typename T>
class PrintStackTopOperator :
	public SingleOperandOperator<T>
{
private:
	std::ostream &stream;

public:
	PrintStackTopOperator(std::ostream &stream);
	const T apply(const T &operand, std::stack<T> &stack);
};

template<typename T>
inline PrintStackTopOperator<T>::PrintStackTopOperator(std::ostream &stream) : stream(stream)
{
}

template<typename T>
inline const T PrintStackTopOperator<T>::apply(const T &operand, std::stack<T> &stack)
{
	stream << operand;
	return operand;
}
