#pragma once

#include <stack>
#include "InvalidStackStateException.h"

using namespace std;

template<typename T>
class Operator
{
public:
	virtual const T apply(stack<T> &stack) = 0;
};

