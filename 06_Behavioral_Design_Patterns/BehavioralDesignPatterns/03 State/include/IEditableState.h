#pragma once
#include "IState.h"

class IEditableState : public IState {
public:
    virtual ~IEditableState() = default;
    void edit(DocumentContext& context) override = 0;
};
