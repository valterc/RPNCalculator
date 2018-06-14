#pragma once
#include "TwoOperandOperator.h"

template<typename T>
class AdditionOperator :
	public TwoOperandOperator<T>
{
public:
	const T apply(const T &firstOperand, const T &secondOperand, stack<T> &stack);

};

template<typename T>
inline const T AdditionOperator<T>::apply(const T &firstOperand, const T &secondOperand, stack<T> &stack)
{
	T result = firstOperand + secondOperand;
	stack.push(result);

	return result;
}