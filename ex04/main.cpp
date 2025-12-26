#include <iostream>
#include <fstream>
#include <string>

void replaceAndWrite(std::string content, std::string s1, std::string s2, std::ofstream& ofs)
{
    size_t pos = 0;
    size_t foundPos;

    while ((foundPos = content.find(s1, pos)) != std::string::npos)
    {
        ofs << content.substr(pos, foundPos - pos);
        ofs << s2;
        pos = foundPos + s1.length();
    }
    ofs << content.substr(pos);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 (search string) cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string content;
    content.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    std::string outFilename = filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if (!ofs.is_open())
    {
        std::cerr << "Error: Could not create output file " << outFilename << std::endl;
        return 1;
    }

    replaceAndWrite(content, s1, s2, ofs);

    ofs.close();
    return 0;
}