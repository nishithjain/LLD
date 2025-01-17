#include "BirdFactory.h"

#include <iostream>
#include <algorithm>

#include "Crow.h"
#include "Hen.h"
#include "Peacock.h"
#include "Sparrow.h"

std::string ToLower(const std::string& str)
{
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return result;
}

std::unique_ptr<Bird> BirdFactory::CreateBirdOfType(const BirdType bird_type)
{
	switch (bird_type)
	{
	case BirdType::CROW:
		return std::make_unique<Crow>();
	case BirdType::HEN:
		return std::make_unique<Hen>();
	case BirdType::PEACOCK:
		return std::make_unique<Peacock>();
	case BirdType::SPARROW:
		return std::make_unique<Sparrow>();
	default:
		return nullptr;
	}
}

std::unique_ptr<Bird> BirdFactory::CreateBirdFromString(const std::string& bird_type)
{
	const std::string lowerBirdType = ToLower(bird_type);
	if (lowerBirdType == "crow") {
		return std::make_unique<Crow>();
	}
	if (lowerBirdType == "hen") {
		return std::make_unique<Hen>();
	}
	if (lowerBirdType == "peacock") {
		return std::make_unique<Peacock>();
	}
	if (lowerBirdType == "sparrow") {
		return std::make_unique<Sparrow>();
	}
	std::cerr << "Unknown bird type: " << bird_type << '\n';
	return nullptr;
}
