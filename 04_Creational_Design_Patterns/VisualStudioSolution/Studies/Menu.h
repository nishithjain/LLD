#pragma once
// Abstract Product C
class Menu {
public:
    virtual ~Menu() = default;
    virtual void Render() const = 0;
};

