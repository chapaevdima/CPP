#include "MySed.hpp"

MySed::MySed(std::string filename)
{
    this->inFile = filename;
    this->outFile = filename + ".replace";
}

MySed::~MySed()
{

}

void MySed::replace(std::string s1, std::string s2)
{
	std::ifstream   ifs(this->inFile.c_str());
	if (ifs.is_open())
	{
		std::string str;
		if (getline(ifs, str, '\0'))
		{
			std::ofstream ofs(this->outFile.c_str());
			size_t pos = str.find(s1);
			if (pos == std::string::npos || s1.length() == 0)
				ofs << str;
			else
			{
				while (pos != std::string::npos)
				{
					str.erase(pos, s1.length());
					str.insert(pos, s2);
					ofs << str.substr(0, pos + s2.length());
					str = str.substr(pos + s2.length(), str.length());
					pos = str.find(s1);
			}
			ofs << str;
			}
			ofs.close();
		} else
		{
			std::cout << "Empty file found." << std::endl;
		}
		ifs.close();
	} else
	{
		std::cout << "Unable to open the file." << std::endl;
		return ;
	}

}
