#pragma once
#include "ILockableState.h"

class LockedState : public ILockableState {
public:
    void view(DocumentContext& context) override;
    void lock(DocumentContext& context) override;
};