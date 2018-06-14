#pragma once

#include <exception>

using namespace std;

class InvalidInputArgumentException : public exception
{
public:
	InvalidInputArgumentException(const char *const message);
	~InvalidInputArgumentException();
};

