#pragma once

#include <exception>

using namespace std;

class InvalidStackStateException : public exception
{
public:
	InvalidStackStateException(const char *const message);
	~InvalidStackStateException();
};

