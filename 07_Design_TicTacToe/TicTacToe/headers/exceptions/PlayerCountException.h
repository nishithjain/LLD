#pragma once
#include <stdexcept>

class PlayerCountException final : public std::invalid_argument
{
public:
	explicit PlayerCountException(const std::string& message);
};

