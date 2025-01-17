#pragma once

// Abstract Product: Vehicle
class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual void Drive() const = 0;
};
