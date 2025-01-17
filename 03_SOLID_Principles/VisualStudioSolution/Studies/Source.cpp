#include <iostream>
#include <memory>
#include <vector>

#include "Bird.h"
#include "Hen.h"
#include "Eagle.h"
#include "Parrot.h"
#include "Penguin.h"
#include "AngryBirds.h"

using namespace std;

int main() {
    vector<unique_ptr<Bird>> birds;

    birds.push_back(make_unique<Hen>("Ginger", "Domestic", "Brown", 2.5f));
    birds.push_back(make_unique<Parrot>("Snowball", "Tropical", "White", 2.8f));

    AngryBirds angryBirds;

    for (const auto& bird : birds) {
        angryBirds.renderBirds(bird); 
    }

	return 0;
}

/***********************************
Our bird name is Ginger which is of Domestic type and is Brown in color.
Ginger is Flying low.
Our bird name is Snowball which is of Tropical type and is White in color.
Snowball is flying with colorful wings.
***********************************/

