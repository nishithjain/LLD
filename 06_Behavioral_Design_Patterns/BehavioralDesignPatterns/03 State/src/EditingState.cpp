#include "EditState.h"
#include "DocumentContext.h"
#include <iostream>

void EditState::view(DocumentContext& context) 
{
    std::cout << "Viewing in editing mode.\n";
}

void EditState::edit(DocumentContext& context) {
    std::cout << "Editing the document.\n";
}