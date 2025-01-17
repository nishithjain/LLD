#pragma once
// Abstract Product A
class Button {
public:
    virtual ~Button() = default;
    virtual void Render() const = 0;
};
