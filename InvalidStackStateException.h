#pragma once

#include <exception>

class InvalidStackStateException : public std::exception
{
public:
	InvalidStackStateException(const char *const message);
	virtual ~InvalidStackStateException() = default;
};

