#pragma once

#include <exception>

using namespace std;

class InvalidOperatorException : exception
{
public:
	InvalidOperatorException(const char *const message);
	~InvalidOperatorException();
};

