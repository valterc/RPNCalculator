#pragma once

#include <exception>

class InvalidOperatorException : public std::exception
{
public:
	InvalidOperatorException(const char *const message);
	virtual ~InvalidOperatorException() = default;
};

