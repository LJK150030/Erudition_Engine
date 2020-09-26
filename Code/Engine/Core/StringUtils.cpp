#include "Engine/Core/StringUtils.hpp"
#include <stdarg.h>


//-----------------------------------------------------------------------------------------------
const int STRINGF_STACK_LOCAL_TEMP_LENGTH = 2048;


//-----------------------------------------------------------------------------------------------
const std::string Stringf(const char* format, ...)
{
	char text_literal[STRINGF_STACK_LOCAL_TEMP_LENGTH];
	va_list variable_argument_list;
	va_start(variable_argument_list, format);
	vsnprintf_s(text_literal, STRINGF_STACK_LOCAL_TEMP_LENGTH, _TRUNCATE, format, variable_argument_list);
	va_end(variable_argument_list);
	text_literal[STRINGF_STACK_LOCAL_TEMP_LENGTH - 1] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

	return std::string(text_literal);
}


//-----------------------------------------------------------------------------------------------
const std::string Stringf(const int max_length, const char* format, ...)
{
	char text_literal_small[STRINGF_STACK_LOCAL_TEMP_LENGTH];
	char* text_literal = text_literal_small;
	if (max_length > STRINGF_STACK_LOCAL_TEMP_LENGTH)
		text_literal = new char[max_length];

	va_list variable_argument_list;
	va_start(variable_argument_list, format);
	vsnprintf_s(text_literal, max_length, _TRUNCATE, format, variable_argument_list);
	va_end(variable_argument_list);
	text_literal[max_length - 1] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

	std::string return_value(text_literal);
	if (max_length > STRINGF_STACK_LOCAL_TEMP_LENGTH)
		delete[] text_literal;

	return return_value;
}
