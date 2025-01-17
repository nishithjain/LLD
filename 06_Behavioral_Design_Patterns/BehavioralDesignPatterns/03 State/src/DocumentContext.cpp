#include <iostream>
#include "DocumentContext.h"

DocumentContext::DocumentContext(std::unique_ptr<IState> initialState)
	: currentState(std::move(initialState))
{
}

void DocumentContext::setState(std::unique_ptr<IState> newState) {
	currentState = std::move(newState);
}

void DocumentContext::view()
{
	currentState->view(*this);
}

void DocumentContext::edit()
{
	try {
		currentState->edit(*this);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}

void DocumentContext::lock()
{
	try {
		currentState->lock(*this);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}
