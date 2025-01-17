#include <iostream>
#include <memory>

#include "Bullet.h"
#include "ChocoChips.h"
#include "ChocolateCone.h"
#include "ChocolateSauce.h"
#include "IIceCream.h"
#include "Mango.h"
#include "Vanilla.h"

int main() {

	CharacterFactory factory;
	std::vector<std::shared_ptr<ICharacter>> text;

	// Create a sample text "HELLO" using shared flyweight characters
	text.push_back(factory.GetCharacter('H'));
	text.push_back(factory.GetCharacter('E'));
	text.push_back(factory.GetCharacter('L'));
	text.push_back(factory.GetCharacter('L'));
	text.push_back(factory.GetCharacter('O'));

	// Display characters with varying extrinsic state (position and font size)
	int positionX = 0;
	for (const auto& i : text)
	{
		i->Display(12, positionX, 10);
		positionX += 20; // Increment positionX for each character
	}

	return 0;
}
