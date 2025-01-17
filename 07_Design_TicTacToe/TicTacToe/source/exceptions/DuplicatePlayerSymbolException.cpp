#include "DuplicatePlayerSymbolException.h"

DuplicatePlayerSymbolException::DuplicatePlayerSymbolException(const std::string& message)
	: invalid_argument(message)
{
}
