#pragma once

#include <exception>

using namespace std;

class InvalidOperatorException : public exception
{
public:
	InvalidOperatorException(const char *const message);
	~InvalidOperatorException();
};

