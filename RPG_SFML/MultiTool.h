#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <variant>


namespace MultiTool
{
	using my_variant = std::variant<std::string, float>;
	std::string FloatToString(float input);
	float StringToFloat(std::string input);

	template<typename T>
	std::vector<T> LoadFromFileAsVector(std::string path)
	{
		std::fstream input_file;
		std::vector<T> output;
		T temp_value;
		input_file.open(path, std::ios::in);

		if (input_file.good())
		{
			while (!input_file.eof())
			{
				input_file >> temp_value;
				output.push_back(temp_value);
			}
		}
		else
		{
			std::cout << "Blad wczytywania pliku funkcja z multitool ";
		}

		return output;
	}
}