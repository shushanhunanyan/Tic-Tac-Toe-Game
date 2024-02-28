#include <fstream>
#include <string>


class SaveOnFile
{
public:
	SaveOnFile(const std::string& filename);

	bool writeToFile(const std::string&);
	bool readFromFile(std::string&);

private:
	std::string m_filename;
};
