#pragma once

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
