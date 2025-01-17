#pragma once
#include "Bird.h"
class Penguin : public Bird {
public:
    Penguin(string name, string type, 
        string color, float weight);
    void eat() override;
};