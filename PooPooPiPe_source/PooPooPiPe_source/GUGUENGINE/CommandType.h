#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *11.1.2019
 *digipen.hagyoeng@gmail.com
 *CommandType.h
 *this is command type
 */
#include <string>

enum class CommandType {
	INVAILD = 0,
	CHAGNESTATECOMMAND,
	QUTICOMMAND,
};

inline CommandType StringToCommand(const std::string& string)
{
	if (string == "CHAGNE_STATE")				return CommandType::CHAGNESTATECOMMAND;
	if (string == "QUTI")				    return CommandType::QUTICOMMAND;
	return CommandType::INVAILD;
}

inline std::string CommandToString(CommandType type)
{
	if (type == CommandType::CHAGNESTATECOMMAND)				return "CHAGNESTATECOMMAND";
	if (type == CommandType::QUTICOMMAND)				        return "QUTICOMMAND";

	return "COMPONENTTYPE_NULL";
}
