#pragma once
#include "IState.h"

class ILockableState : public IState {
public:
    virtual ~ILockableState() = default;
    void lock(DocumentContext& context) override = 0;
};
