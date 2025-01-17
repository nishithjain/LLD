#pragma once
#include "GateOperator.h"
#include "GateStatus.h"
#include "GateType.h"

class Gate
{
	// Every class will be going to be a table in DB.
	// For every table we need to have an ID.
	int gate_id_ = -1; 
	int gate_number_ = -1;
	GateOperator gate_operator_;
	GateType gate_type_;
	GateStatus gate_status_;

};

