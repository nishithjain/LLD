#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Image {};

class Bullet
{
	// Position coordinates (x, y, z) in the game world
	double position_x_;
	double position_y_;
	double position_z_;

	// Direction vector
	double direction_x_;
	double direction_y_;
	double direction_z_;

	// Bullet attributes
	double velocity_;            // Speed of the bullet
	double damage_;              // Damage dealt on impact
	double range_;               // Maximum range before disappearing
	double gravity_effect_;      // Effect of gravity on the bullet
	double lifespan_;            // Time duration bullet exists before despawning
	std::string caliber_;       // Bullet type, e.g., "5.56mm", "7.62mm"
	std::string hit_effect_;    // Visual effect on impact
	std::string trail_effect_;  // Visual trail effect
	Image image_;
public:
};

class BulletType {
	// Intrinsic attributes
	double damage_;
	double range_;
	double gravity_effect_;
	std::string caliber_;
	std::string hit_effect_;
	std::string trail_effect_;
	Image image_;
public:

};

class BulletInAction {
	// Extrinsic attributes
	double position_x_;
	double position_y_;
	double position_z_;
	double direction_x_;
	double direction_y_;
	double direction_z_;
	double velocity_;
	double lifespan_;

	std::shared_ptr<BulletType> bullet_type_;
public:

};


#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
// Flyweight class: ICharacter
class ICharacter {
public:
	virtual void Display(int font_size, int position_x, int position_y) = 0;
	virtual ~ICharacter() = default;
};

// ConcreteFlyweight class: ConcreteCharacter
class ConcreteCharacter final : public ICharacter {
	char symbol_;

public:
	explicit ConcreteCharacter(const char sym) : symbol_(sym) {}

	// Displays character with extrinsic state
	void Display(const int font_size, const int position_x,
		const int position_y) override
	{
		std::cout << "Character: " << symbol_ << " at ("
			<< position_x << ", " << position_y
			<< "), Font Size: " << font_size << '\n';
	}
};

// FlyweightFactory class: Manages flyweight objects
class CharacterFactory {
	std::unordered_map<char, std::shared_ptr<ICharacter>> characters_;

public:
	std::shared_ptr<ICharacter> GetCharacter(char symbol) {
		// Check if character already exists in the map
		if (characters_.find(symbol) == characters_.end()) {
			// Create new character and store it if it does not exist
			characters_[symbol] = std::make_shared<ConcreteCharacter>(symbol);
			std::cout << "Creating new character: " << symbol << '\n';
		}
		return characters_[symbol];
	}
};


// Flyweight class
class Character {
	char symbol_;
public:
	explicit Character(const char sym) : symbol_(sym) {}
	void Display(const int font_size, const int position_x, 
		const int position_y) const
	{
		std::cout << "Character: " << symbol_ << " at (" << position_x
			<< ", " << position_y << "), Font Size: " << font_size << '\n';
	}
};

// Character factory
class AnotherCharacterFactory {
	std::unordered_map<char, std::shared_ptr<Character>> characters_;
public:
	std::shared_ptr<Character> GetCharacter(char symbol)
	{
		if (characters_.find(symbol) == characters_.end())
		{
			characters_[symbol] = std::make_shared<Character>(symbol);
			std::cout << "Creating new character: " << symbol << '\n';
		}
		return characters_[symbol];
	}
};