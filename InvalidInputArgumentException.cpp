#include "InvalidInputArgumentException.h"



InvalidInputArgumentException::InvalidInputArgumentException(const char *const message) : exception::exception(message)
{
}
