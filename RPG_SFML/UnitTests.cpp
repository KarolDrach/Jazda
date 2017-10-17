#include <Windows.h>
#include <iostream>
#include "UnitTests.h"

void UnitTests::PrintConsolePassed(std::string input)
{
	auto HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(HANDLE, FOREGROUND_GREEN);
	std::cout << input << " PASSED\n";
	SetConsoleTextAttribute(HANDLE, 1);
}

void UnitTests::PrintConsoleFailed(std::string input)
{
	auto HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(HANDLE, FOREGROUND_RED);
	std::cout << input << " FAILED\n";
	SetConsoleTextAttribute(HANDLE, 1);
}

UnitTests::UnitTests()
{
}

UnitTests::~UnitTests()
{
}
