#include "std_lib_facilities.h"

const char *findx(const char *s, const char *x)
{
    if (s == nullptr || x == nullptr)
        error("nullptr was sent to findx()");

    const char *ptr = nullptr;
    int count = 0;

    while (*s)
        if (*x == *s++)
        {
            ptr = s - 1;
            while (*(++x))
            {
                count++;
                if (*x != *s++)
                //wrong occurrence
                {
                    ptr = nullptr;
                    s -= count; //return pointer s back to the first position
                    x -= count; //return pointer x back to the first position
                    count = 0;
                    break; //continue the searching
                }
            }
            if (ptr)
                return ptr; //first occurrence
        }
    return nullptr; //nothing found
}

int main()
try
{
    char cstr[] = "The Treasure of Monte Cristo";
    char word[] = "Monte";
    const char *ptr = findx(cstr, word);
    if (ptr)
        cout << ptr << endl;
    else
        error("There is no such a word ", word);
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
