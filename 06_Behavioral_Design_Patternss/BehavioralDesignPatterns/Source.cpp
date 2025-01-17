#include <iostream>
#include <memory>
#include "DocumentContext.h"
#include "EditState.h"
#include "ViewState.h"
#include "LockedState.h"

int main()
{
    DocumentContext document(std::make_unique<EditState>());

    std::cout << "Current State: Editing\n";
    document.view();  // Should allow viewing
    document.edit();  // Should allow editing

    // Change to ReadOnly state
    document.setState(std::make_unique<ViewState>());
    std::cout << "\nCurrent State: ReadOnly\n";
    document.view();  // Should allow viewing in read-only mode
    document.edit();  // Should not allow editing

    // Change to Locked state
    document.setState(std::make_unique<LockedState>());
    std::cout << "\nCurrent State: Locked\n";
    document.view();  // Should deny viewing
    document.edit();  // Should deny editing

	return 0;
}
