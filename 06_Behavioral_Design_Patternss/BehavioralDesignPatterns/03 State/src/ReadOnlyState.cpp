#include "ViewState.h"
#include "DocumentContext.h"
#include <iostream>

void ViewState::view(DocumentContext& context) {
    std::cout << "Viewing in read-only mode.\n";
}