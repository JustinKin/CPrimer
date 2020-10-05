#include <iostream>
#include <fstream>
#include <vector>

std::istream &IOtest(std::istream &);

void PushLine(std::ifstream &, std::vector<std::string> &);

void PushWord(std::ifstream &, std::vector<std::string> &);

void Show(std::vector<std::string> &);

std::istream& ISTest(std::istream&);

struct PersonInfo
{
     std::string name;
     std::vector<std::string> phones;
};

std::string Format(const std::string &);
