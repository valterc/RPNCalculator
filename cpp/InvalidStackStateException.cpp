#include "InvalidStackStateException.h"



InvalidStackStateException::InvalidStackStateException(const char *const message) : exception::exception(message)
{
}
