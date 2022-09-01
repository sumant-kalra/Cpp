#define DATA_MINI_SERIES_MAIN 1
#define STD_OPTIONAL 0
#define STD_VARIANT 1
#define STD_ANY 0

#if DATA_MINI_SERIES_MAIN

#include <iostream>
#include <fstream>
#include <sstream>

#if STD_OPTIONAL
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
            std::cerr << "Reading from the file has failed\n";

        std::cout << fileContents.value_or("Reading from the file has failed\n");
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
#endif // STD_OPTIONAL

#if STD_VARIANT
#include <variant>

enum class ERROR_CODE
{
    FAILED_TO_READ = 1
};

static std::variant<std::string, ERROR_CODE> readFromFile(std::ifstream &file)
{
    std::stringstream ss;
    std::string tempString;

    // For the other cases when we are not checking the state all the time, use fstream's exception mask instead of the code below
    while (getline(file, tempString))
    {
        ss << tempString << '\n';
    }
    if (!file.eof())
        return ERROR_CODE::FAILED_TO_READ;

    return ss.str();
}

static std::variant<std::string, ERROR_CODE> openAndReadFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
        throw std::invalid_argument("Failed to open the file");

    std::variant<std::string, ERROR_CODE> fileContents = readFromFile(file);

    file.close();

    return fileContents;
}

int main(int argc, char const *argv[])
{
    try
    {

        std::variant<std::string, ERROR_CODE> fileContents = openAndReadFromFile("TestFile.txt");
        if (std::get_if<std::string>(&fileContents))
        {
            std::cout << std::get<std::string>(fileContents);
        }
        else
        {
            std::cerr << "Reading from the file has failed with the error code : " << int(std::get<ERROR_CODE>(fileContents)) << "\n";
        }
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
#endif // STD_VARIANT

#if STD_ANY
#endif // STD_ANY

#endif // DATA_MINI_SERIES_MAIN
