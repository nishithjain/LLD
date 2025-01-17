#include "LockedState.h"
#include "DocumentContext.h"
#include <iostream>

void LockedState::view(DocumentContext& context) {
    std::cout << "Cannot View. Document Locked!.\n";
}

void LockedState::lock(DocumentContext& context) {
    std::cout << "Document is now locked.\n";
}