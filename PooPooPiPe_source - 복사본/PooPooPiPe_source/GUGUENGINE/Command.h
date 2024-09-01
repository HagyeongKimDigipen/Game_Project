#pragma once

#include "CommandType.h"

class Command
{
public:
	Command(CommandType type);
	virtual ~Command() {};
	virtual void Execute() = 0;
private:
	CommandType mType;
};

