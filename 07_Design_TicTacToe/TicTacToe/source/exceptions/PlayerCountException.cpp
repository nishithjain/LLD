#include "PlayerCountException.h"

PlayerCountException::PlayerCountException(const std::string& message)
	: std::invalid_argument(message)
{
}
