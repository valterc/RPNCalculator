#include "InvalidOperatorException.h"



InvalidOperatorException::InvalidOperatorException(const char *const message) : exception::exception(message)
{
}


InvalidOperatorException::~InvalidOperatorException()
{
	this->exception::~exception();
}
