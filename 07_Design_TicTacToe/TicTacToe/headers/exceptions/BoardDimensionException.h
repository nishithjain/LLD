#pragma once
#include <stdexcept>

class BoardDimensionException final : public std::invalid_argument
{
public:
	explicit BoardDimensionException(const std::string& message);
};

