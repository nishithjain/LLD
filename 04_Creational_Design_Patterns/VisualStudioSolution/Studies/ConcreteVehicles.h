#pragma once
#include "Vehicle.h"

class Car final : public Vehicle {
public:
    void Drive() const override;
};

class Buggy final : public Vehicle {
public:
    void Drive() const override;
};

class MonsterTruck final : public Vehicle {
public:
    void Drive() const override;
};

class Dacia final : public Vehicle {
public:
    void Drive() const override;
};

class Motorcycle final : public Vehicle {
public:
    void Drive() const override;
};