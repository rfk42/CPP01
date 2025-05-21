#include <iostream>
#include <fstream>
#include <string>

std::string customReplace(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string result;
	size_t i = 0;
	size_t found;

	while ((found = line.find(s1, i)) != std::string::npos)
	{
		result += line.substr(i, found - i);
		result += s2;
		i = found + s1.length();
	}
	result += line.substr(i);
	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return 1;
	}
	
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error creating output file." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
		outfile << customReplace(line, s1, s2) << std::endl;

	infile.close();
	outfile.close();
	return 0;
}

