#include "AngryBirds.h"
#include "IFlyable.h"

#include <memory>
#include <iostream>
using namespace std;

void AngryBirds::renderBirds(const std::unique_ptr<Bird>& bird) 
{
    cout << "Our bird name is " << bird->getName() << " which is of "
        << bird->getType() << " type and is " << bird->getColor()
        << " in color.\n";

    auto flyableBird = dynamic_cast<IFlyable*>(bird.get());
    if (flyableBird) 
    {
        flyableBird->fly();
    }
}
