#pragma once

#include <stack>
#include "InvalidStackStateException.h"

template<typename T>
class Operator
{
public:
	virtual const T apply(std::stack<T> &stack) = 0;
};

