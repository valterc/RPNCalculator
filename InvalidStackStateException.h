#pragma once

#include <exception>

using namespace std;

class InvalidStackStateException : exception
{
public:
	InvalidStackStateException(const char *const message);
	~InvalidStackStateException();
};

