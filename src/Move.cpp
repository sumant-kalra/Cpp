#define MOVE_MAIN 1
#if MOVE_MAIN

#include <cstdio>
#include <iostream>

class String
{
private:
    char *m_string;
    u_int32_t m_size;

public:
    String(const char *string)
    {
        m_size = strlen(string) + 1;
        m_string = new char[m_size];
        strcpy(m_string, string);
    }

    String(const String &other)
    {
        m_size = other.m_size;
        m_string = new char[m_size];
        strcpy(m_string, other.m_string);
        printf("Copied String!\n");
    }

    String(String &&other)
    {
        m_size = other.m_size;
        m_string = other.m_string;

        other.m_size = 0;
        other.m_string = nullptr;
        printf("Moved String!\n");
    }

    void printString()
    {
        printf("%s\n", m_string);
    }

    ~String()
    {
        if (m_string)
            delete[] m_string;
        else
            delete m_string;
        printf("String deleted\n");
    }
};

class Entity
{
private:
    String m_name;

public:
    Entity(const String &name) : m_name(name)
    {
        printf("Inside Copy Constructor\n");
    }

    Entity(String &&name) : m_name(std::move(name))
    {
        printf("Inside Constructor with R-value\n");
    }

    void print()
    {
        m_name.printString();
    }
};

int main(int argc, char const *argv[])
{
    Entity entityObj(String("Sumant"));
    entityObj.print();

    return 0;
}

#endif