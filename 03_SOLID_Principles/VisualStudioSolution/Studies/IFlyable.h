#pragma once

class IFlyable {
public:
    virtual void fly() = 0;
    virtual ~IFlyable() = default;
};