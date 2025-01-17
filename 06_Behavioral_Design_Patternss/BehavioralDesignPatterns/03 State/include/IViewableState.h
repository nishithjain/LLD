#pragma once
#include "IState.h"

class IViewableState : public IState {
public:
    virtual ~IViewableState() = default;
};
