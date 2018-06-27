#pragma once
#include "TwoOperandOperator.h"

template<typename T>
class MultiplicationOperator :
	public TwoOperandOperator<T>
{
public:
	const T apply(const T &firstOperand, const T &secondOperand, std::stack<T> &stack);

};

template<typename T>
inline const T MultiplicationOperator<T>::apply(const T &firstOperand, const T &secondOperand, std::stack<T> &stack)
{
	T result = firstOperand * secondOperand;
	stack.push(result);

	return result;
}