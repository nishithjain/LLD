#include "BoardDimensionException.h"

BoardDimensionException::BoardDimensionException(const std::string& message) :
	invalid_argument(message)
{
}
