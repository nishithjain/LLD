#pragma once
// Abstract Product B
class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void Render() const = 0;
};
