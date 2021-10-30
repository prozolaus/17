#include "std_lib_facilities.h"

void to_lower(char *s)
{
    if (s == nullptr)
        error("Nullptr in to_lower(char*)!");
    while (*s)
    {
        if (*s >= 65 && *s <= 90)   //from ASCII table from A to Z (65...90)
            *s += 32;               //a = A+32 (where A==65) etc.
        s++;
    }
}

int main()
try
{
    char stroka[] = "Hello, World!";
    char* hw = stroka;
    cout << stroka <<endl;
    to_lower(hw);
    cout << stroka <<endl;
}
catch (const std::exception &e)
{
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Some kind of exception\n";
    return 2;
}