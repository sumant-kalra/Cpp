#define STRUCTBINDING_OPTDATAMAIN 1
#if STRUCTBINDING_OPTDATAMAIN

#include <iostream>
#include <tuple>
#include <string>
#include <optional>

static std::tuple<int, std::string> testFunction()
{
    return {2, std::string("Nobody")};
}

static std::optional<std::string> testFunction2()
{
#define RETURN 0
    if (RETURN)
        return std::string("Where I am now?");
    else
        return {};
}

int main(int argc, char const *argv[])
{
    auto result = testFunction();
    std::cout << std::get<0>(result) << "\n";
    std::cout << std::get<1>(result) << "\n";

    int i = -1;
    std::string who;

    std::tie(i, who) = testFunction();
    std::cout << i << "\n";
    std::cout << who << "\n";

    /// Structured Bindings for pairs and tuples (since C++17)
    auto [var1, var2] = testFunction();
    std::cout << var1 << "\n";
    std::cout << var2 << "\n";

    auto data = testFunction2();
    if (data.has_value())           // if(data)
        std::cout << *data << "\n"; // dereference the output to get the value
                                    // data.value()
    else
        std::cout << "Nothing\n";

    return 0;
}

#endif