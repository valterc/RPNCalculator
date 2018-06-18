#pragma once

#include <exception>

class InvalidInputArgumentException : public std::exception
{
public:
	InvalidInputArgumentException(const char *const message);
	virtual ~InvalidInputArgumentException() = default;
};

