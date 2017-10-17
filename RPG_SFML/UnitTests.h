#pragma once
#include <string>

class UnitTests
{
private:
	UnitTests();
public:
	UnitTests(const UnitTests &) = delete;
	void operator=(const UnitTests &) = delete;

	inline static UnitTests& Instance()
	{
		static UnitTests instance;
		return instance;
	}
	
	static void PrintConsolePassed(std::string);
	static void PrintConsoleFailed(std::string);
	~UnitTests();
};

