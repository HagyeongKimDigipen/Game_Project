#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *11.1.2019
 *digipen.hagyeong@gmail.com
 *Command.h
 *this is command 
 */
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

