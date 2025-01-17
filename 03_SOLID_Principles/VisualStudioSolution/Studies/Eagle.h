#include "Bird.h"
#include "IFlyable.h"

class Eagle : public Bird, public IFlyable {
public:
	Eagle(string name, string type,
		string color, float weight);
	void fly() override;
	void eat() override;
};
