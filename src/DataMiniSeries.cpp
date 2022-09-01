#define DATA_MINI_SERIES_MAIN 1
#if DATA_MINI_SERIES_MAIN

#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>

static std::optional<std::string> readFromFile(std::ifstream &file)
{
    std::stringstream ss;
    std::string tempString;

    // For the other cases when we are not checking the state all the time, use fstream's exception mask instead of the code below
    while (getline(file, tempString))
    {
        ss << tempString << '\n';
    }
    if (!file.eof())
        return {};

    return ss.str();
}

static std::optional<std::string> openAndReadFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
        throw std::invalid_argument("Failed to open the file");

    std::optional<std::string> fileContents;

    fileContents = readFromFile(file);
    file.close();
    if (fileContents.has_value())
        return fileContents.value();
    else
        return {};
}

int main(int argc, char const *argv[])
{
    try
    {
        std::optional<std::string> fileContents = openAndReadFromFile("TestFile.txt");
        if (fileContents)
            std::cout << *fileContents;
        else
            std::cerr << "Reading from the file failed\n";
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