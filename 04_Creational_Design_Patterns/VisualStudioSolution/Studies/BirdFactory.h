#pragma once
#include <memory>
#include <string>

#include "Bird.h"
#include "BirdType.h"

class BirdFactory
{
public:
	static std::unique_ptr<Bird> CreateBirdOfType(BirdType bird_type);
	static std::unique_ptr<Bird> CreateBirdFromString(const std::string& bird_type);
};

