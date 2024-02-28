#include "SaveAsString.h"


#include <iostream>
#include <fstream>


SaveOnFile::SaveOnFile(const std::string& name) : m_filename{name} {}

bool SaveOnFile::writeToFile(const std::string& str)
{
	std::ofstream file(m_filename);
	if (!file.is_open()) {
		std::cerr << "Error while opening the file." << std::endl;
		return false;
	}

	file << str;
	file.close();
	return true;
}


bool SaveOnFile::readFromFile(std::string& str)
{
	std::ifstream file(m_filename);
	if (!file.is_open()) {
                std::cerr << "Error while opening the file." << std::endl;
                return false;
        }

	str.clear();

	std::string line;
	while (std::getline(file, line)) {
		str += line;
	}
	
	file.close();
	return true;
}
