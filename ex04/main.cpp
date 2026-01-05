#include <iostream>
#include <fstream>
#include <string>

void replaceContent(const std::string& content, const std::string& s1, const std::string& s2, std::ofstream& ofs)
{
    size_t pos = 0;
    size_t foundPos;

    if (s1.empty())
    {
        ofs << content;
        return;
    }
    while ((foundPos = content.find(s1, pos)) != std::string::npos)
    {
        ofs << content.substr(pos, foundPos - pos);
        ofs << s2;
        pos = foundPos + s1.length();
    }
    ofs << content.substr(pos);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return 1;
    }
    std::string outFilename = filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if (!ofs.is_open())
    {
        std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
        ifs.close();
        return 1;
    }
    std::string content;
    char c;
    while (ifs.get(c))
    {
        content += c;
    }
    replaceContent(content, s1, s2, ofs);
    ifs.close();
    ofs.close();
    return 0;
}