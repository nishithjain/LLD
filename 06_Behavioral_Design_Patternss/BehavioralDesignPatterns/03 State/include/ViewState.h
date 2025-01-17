#pragma once
#include "IViewableState.h"

class ViewState : public IViewableState {
public:
    void view(DocumentContext& context) override;
};