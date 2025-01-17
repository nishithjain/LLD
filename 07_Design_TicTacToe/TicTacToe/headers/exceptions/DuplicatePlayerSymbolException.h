#pragma once
#include <stdexcept>

class DuplicatePlayerSymbolException final : public std::invalid_argument
{
public:
	explicit DuplicatePlayerSymbolException(const std::string& message);
};

