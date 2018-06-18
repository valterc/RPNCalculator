#pragma once
#include "SingleOperandOperator.h"

template<typename T>
class SwapSignOperator :
	public SingleOperandOperator<T>
{
public:
	const T apply(const T &operand, std::stack<T> &stack);

};

template<typename T>
const T SwapSignOperator<T>::apply(const T &operand, std::stack<T> &stack)
{
	stack.pop();

	T result = -operand;
	stack.push(result);

	return result;
}