#include "Bird.h"
#include <memory>

class AngryBirds {
public:
	void renderBirds(const std::unique_ptr<Bird>& bird);
};
