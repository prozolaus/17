#include "std_lib_facilities.h"

char *strdup(const char *cstr)
{
    if (cstr == nullptr)
        error("Nullptr was sent to strdup()");
    int n = 0, k = 0;
    while (true)
    {
        if (!cstr[k++])
            break;
        n++;
    }
    char *s = new char[n];
    for (int i = 0; i < n; i++)
        s[i] = cstr[i];
    return s;
}

char *findx(const char *s, const char *x)
{
    if (s == nullptr || x == nullptr)
        error("nullptr was sent to findx()");

    char *ptr = nullptr, *s1 = strdup(s), *s2 = strdup(x);  //copied strings with operator "new", because we cannot get pointer to const 
    int count1 = 0, count2 = 0;   //for going back to first positions of s1 and s2 and then deleting them
    
    while (*s1)
    {
        count1++;
        if (*s2 == *s1++)
        {
            ptr = s1 - 1;
            while (*(++s2))
            {
                count2++;
                if (*s2 != *s1++)
                {
                    ptr = nullptr;
                    s1 -= count2;
                    s2 -= count2;
                    count2 = 0;
                    break;
                }
            }
            if (ptr)
                return ptr;
        }
    }
    s1 -= count1;
    delete[] s1;
    delete[] s2;
    return nullptr;
}

int main()
try
{
    char cstr[] = "of Monte Cristo";
    char word[] = "Monte";
    char *ptr = findx(cstr, word);
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
