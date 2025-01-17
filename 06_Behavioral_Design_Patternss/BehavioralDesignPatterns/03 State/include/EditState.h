#pragma once
#include "IEditableState.h"

class EditState : public IEditableState
{
public:
    void view(DocumentContext& context) override;
    void edit(DocumentContext& context) override;
};

