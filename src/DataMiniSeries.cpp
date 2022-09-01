#define DATA_MINI_SERIES_MAIN 1
#if DATA_MINI_SERIES_MAIN

#include <iostream>
#include <fstream>
#include <sstream>

static std::string readFromFile(std::ifstream &file)
{
    std::stringstream ss;
    std::string tempString;

    // For the other cases when we are not checking the state all the time, use fstream's exception mask instead of the code below
    while (getline(file, tempString))
    {
        ss << tempString << '\n';
    }
    if (!file.eof())
    {
        throw std::invalid_argument("Failed to read the file");
    }

    return ss.str();
}

static std::string openAndReadFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
        throw std::invalid_argument("Failed to open the file");

    std::string fileContents;
    try
    {
        fileContents = readFromFile(file);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown Error!\n";
    }

    file.close();
    return fileContents;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::cout << openAndReadFromFile("TestFile.txt");
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown Error!\n";
    }

    return 0;
}

#endif