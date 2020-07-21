//-----------------------------------------------------------------------------------------------
// ErrorWarningAssert.cpp
//

//-----------------------------------------------------------------------------------------------
#ifdef _WIN32
#define PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

//-----------------------------------------------------------------------------------------------
#include "Engine/Core/ErrorWarningAssert.hpp"
#include "Engine/Core/StringUtils.hpp"
#include <cstdarg>
#include <iostream>


//-----------------------------------------------------------------------------------------------
bool IsDebuggerAvailable()
{
#if defined( PLATFORM_WINDOWS )
	
	typedef BOOL(CALLBACK IsDebuggerPresentFunc)();

	// Get a handle to KERNEL32.DLL
	static HINSTANCE h_instance_kernel32 = GetModuleHandle(TEXT("KERNEL32"));
	if (!h_instance_kernel32)
	{
		return false;
	}

	// Get a handle to the IsDebuggerPresent() function in KERNEL32.DLL
	static IsDebuggerPresentFunc* is_debugger_present_func = static_cast<IsDebuggerPresentFunc*>(GetProcAddress(
		h_instance_kernel32, "IsDebuggerPresent"));
	
	if (!is_debugger_present_func)
	{
		return false;
	}

	// Now CALL that function and return its result
	static BOOL is_debugger_available = is_debugger_present_func();
	return (is_debugger_available == TRUE);
	
#else
	return false;
#endif
}


//-----------------------------------------------------------------------------------------------
void DebuggerPrintf(const char* message_format, ...)
{
	const int message_max_length = 2048;
	char message_literal[message_max_length];
	va_list variable_argument_list;
	
	va_start(variable_argument_list, message_format);
	vsnprintf_s(message_literal, message_max_length, _TRUNCATE, message_format, variable_argument_list);
	va_end(variable_argument_list);
	
	message_literal[message_max_length - 1] = '\0'; // In case vsnprintf overran (doesn't auto-terminate)

#if defined( PLATFORM_WINDOWS )
	if (IsDebuggerAvailable())
	{
		OutputDebugStringA(message_literal);
	}
#endif

	std::cout << message_literal;
}


//-----------------------------------------------------------------------------------------------
// Converts a SeverityLevel to a Windows MessageBox icon type (MB_etc)
//
#if defined( PLATFORM_WINDOWS )
UINT GetWindowsMessageBoxIconFlagForSeverityLevel(const SeverityLevel severity)
{
	switch (severity)
	{
		case SEVERITY_INFORMATION: return MB_ICONASTERISK; // blue circle with 'i' in Windows 7
		case SEVERITY_QUESTION: return MB_ICONQUESTION; // blue circle with '?' in Windows 7
		case SEVERITY_WARNING: return MB_ICONEXCLAMATION; // yellow triangle with '!' in Windows 7
		case SEVERITY_FATAL: return MB_ICONHAND; // red circle with 'x' in Windows 7
		default: return MB_ICONEXCLAMATION;
	}
}
#endif


//-----------------------------------------------------------------------------------------------
const char* FindStartOfFileNameWithinFilePath(const char* file_path)
{
	if (file_path == nullptr)
	{
		return nullptr;
	}

	const size_t path_len = strlen(file_path);
	const char* scan = file_path + path_len; // start with null terminator after last character
	while (scan > file_path)
	{
		--scan;

		if (*scan == '/' || *scan == '\\')
		{
			++scan;
			break;
		}
	}

	return scan;
}


//-----------------------------------------------------------------------------------------------
void SystemDialogue_Okay(const std::string& message_title, const std::string& message_text, const SeverityLevel severity)
{
#if defined( PLATFORM_WINDOWS )
	{
		ShowCursor(TRUE);
		const UINT dialogue_icon_type_flag = GetWindowsMessageBoxIconFlagForSeverityLevel(severity);
		MessageBoxA(nullptr, message_text.c_str(), message_title.c_str(), MB_OK | 
			dialogue_icon_type_flag | MB_TOPMOST);
		ShowCursor(FALSE);
	}
#endif
}


//-----------------------------------------------------------------------------------------------
// Returns true if OKAY was chosen, false if CANCEL was chosen.
//
bool SystemDialogue_OkayCancel(const std::string& message_title, const std::string& message_text, const SeverityLevel severity)
{
	bool is_answer_okay = true;

#if defined( PLATFORM_WINDOWS )
	{
		ShowCursor(TRUE);
		const UINT dialogue_icon_type_flag = GetWindowsMessageBoxIconFlagForSeverityLevel(severity);
		const int button_clicked = MessageBoxA(nullptr, message_text.c_str(), message_title.c_str(),
			MB_OKCANCEL | dialogue_icon_type_flag | MB_TOPMOST);
		is_answer_okay = (button_clicked == IDOK);
		ShowCursor(FALSE);
	}
#endif

	return is_answer_okay;
}


//-----------------------------------------------------------------------------------------------
// Returns true if YES was chosen, false if NO was chosen.
//
bool SystemDialogue_YesNo(const std::string& message_title, const std::string& message_text, const SeverityLevel severity)
{
	bool is_answer_yes = true;

#if defined( PLATFORM_WINDOWS )
	{
		ShowCursor(TRUE);
		const UINT dialogue_icon_type_flag = GetWindowsMessageBoxIconFlagForSeverityLevel(severity);
		const int button_clicked = MessageBoxA(nullptr, message_text.c_str(), message_title.c_str(),
			MB_YESNO | dialogue_icon_type_flag | MB_TOPMOST);
		is_answer_yes = (button_clicked == IDYES);
		ShowCursor(FALSE);
	}
#endif

	return is_answer_yes;
}


//-----------------------------------------------------------------------------------------------
// Returns 1 if YES was chosen, 0 if NO was chosen, -1 if CANCEL was chosen.
//
int SystemDialogue_YesNoCancel(const std::string& message_title, const std::string& message_text, const SeverityLevel severity)
{
	int answer_code = 1;

#if defined( PLATFORM_WINDOWS )
	{
		ShowCursor(TRUE);
		const UINT dialogue_icon_type_flag = GetWindowsMessageBoxIconFlagForSeverityLevel(severity);
		const int button_clicked = MessageBoxA(nullptr, message_text.c_str(), message_title.c_str(),
			MB_YESNOCANCEL | dialogue_icon_type_flag | MB_TOPMOST);
		answer_code = (button_clicked == IDYES ? 1 : (button_clicked == IDNO ? 0 : -1));
		ShowCursor(FALSE);
	}
#endif

	return answer_code;
}


//-----------------------------------------------------------------------------------------------
__declspec(noreturn) void FatalError(const char* file_path, const char* function_name, const int line_num,
	const std::string& reason_for_error, const char* condition_text)
{
	std::string error_message = reason_for_error;
	if (reason_for_error.empty())
	{
		if (condition_text)
		{
			error_message = Stringf("ERROR: \"%s\" is false!", condition_text);
		}
		else
		{
			error_message = "Unspecified fatal error";
		}
	}

	const char* file_name = FindStartOfFileNameWithinFilePath(file_path);
	const std::string app_name = "Unnamed Application";
	const std::string full_message_title = app_name + " :: Error";
	std::string full_message_text = error_message;
	full_message_text += "\n\nThe application will now close.\n";
	const bool is_debugger_present = (IsDebuggerPresent() == TRUE);
	if (is_debugger_present)
	{
		full_message_text += "\nDEBUGGER DETECTED!\nWould you like to break and debug?\n  (Yes=debug, No=quit)\n";
	}

	full_message_text += "\n---------- Debugging Details Follow ----------\n";
	if (condition_text)
	{
		full_message_text += Stringf(
			"\nThis error was triggered by a run-time condition check:\n  %s\n  from %s(), line %i in %s\n",
			condition_text, function_name, line_num, file_name);
	}
	else
	{
		full_message_text += Stringf("\nThis was an unconditional error triggered by reaching\n line %i of %s, in %s()\n",
			line_num, file_name, function_name);
	}

	DebuggerPrintf("\n==============================================================================\n");
	DebuggerPrintf("RUN-TIME FATAL ERROR on line %i of %s, in %s()\n", line_num, file_name, function_name);
	DebuggerPrintf("%s(%d): %s\n", file_path, line_num, error_message.c_str());
	// Use this specific format so Visual Studio users can double-click to jump to file-and-line of error
	DebuggerPrintf("==============================================================================\n\n");

	if (is_debugger_present)
	{
		const bool is_answer_yes = SystemDialogue_YesNo(full_message_title, full_message_text, SEVERITY_FATAL);
		ShowCursor(TRUE);
		if (is_answer_yes)
		{
			__debugbreak();
		}
	}
	else
	{
		SystemDialogue_Okay(full_message_title, full_message_text, SEVERITY_FATAL);
		ShowCursor(TRUE);
	}

	exit(0);
}


//-----------------------------------------------------------------------------------------------
void RecoverableWarning(const char* file_path, const char* function_name, int line_num,
	const std::string& reason_for_warning, const char* condition_text)
{
	std::string error_message = reason_for_warning;
	if (reason_for_warning.empty())
	{
		if (condition_text)
		{
			error_message = Stringf("WARNING: \"%s\" is false!", condition_text);
		}
		else
		{
			error_message = "Unspecified warning";
		}
	}

	const char* file_name = FindStartOfFileNameWithinFilePath(file_path);
	const std::string app_name = "Unnamed Application";
	const std::string full_message_title = app_name + " :: Warning";
	std::string full_message_text = error_message;

	const bool is_debugger_present = (IsDebuggerPresent() == TRUE);
	if (is_debugger_present)
	{
		full_message_text +=
			"\n\nDEBUGGER DETECTED!\nWould you like to continue running?\n  (Yes=continue, No=quit, Cancel=debug)\n";
	}
	else
	{
		full_message_text += "\n\nWould you like to continue running?\n  (Yes=continue, No=quit)\n";
	}

	full_message_text += "\n---------- Debugging Details Follow ----------\n";
	if (condition_text)
	{
		full_message_text += Stringf(
			"\nThis warning was triggered by a run-time condition check:\n  %s\n  from %s(), line %i in %s\n",
			condition_text, function_name, line_num, file_name);
	}
	else
	{
		full_message_text += Stringf(
			"\nThis was an unconditional warning triggered by reaching\n line %i of %s, in %s()\n",
			line_num, file_name, function_name);
	}

	DebuggerPrintf("\n------------------------------------------------------------------------------\n");
	DebuggerPrintf("RUN-TIME RECOVERABLE WARNING on line %i of %s, in %s()\n", line_num, file_name, function_name);
	DebuggerPrintf("%s(%d): %s\n", file_path, line_num, error_message.c_str());
	// Use this specific format so Visual Studio users can double-click to jump to file-and-line of error
	DebuggerPrintf("------------------------------------------------------------------------------\n\n");

	if (is_debugger_present)
	{
		const int answer_code = SystemDialogue_YesNoCancel(full_message_title, full_message_text, SEVERITY_WARNING);
		ShowCursor(TRUE);
		if (answer_code == 0) // "NO"
		{
			exit(0);
		}
		if (answer_code == -1) // "CANCEL"
		{
			__debugbreak();
		}
	}
	else
	{
		const bool is_answer_yes = SystemDialogue_YesNo(full_message_title, full_message_text, SEVERITY_WARNING);
		ShowCursor(TRUE);
		if (!is_answer_yes)
		{
			exit(0);
		}
	}
}
