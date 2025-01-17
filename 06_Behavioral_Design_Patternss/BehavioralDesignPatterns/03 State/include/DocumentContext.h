#pragma once
#include <memory>
#include "IState.h"
#include "IViewableState.h"
#include "IEditableState.h"
#include "ILockableState.h"

class DocumentContext
{
	std::unique_ptr<IState> currentState;

public:
	DocumentContext(std::unique_ptr<IState> initialState);
	void setState(std::unique_ptr<IState> newState);

	void view();
	void edit();
	void lock();
};

