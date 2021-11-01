#include "std_lib_facilities.h"

char *addchartotext(char *t, const char c)
{
    int count = 0;
    while (t[count++])
        ;
    char *t2 = new char[count];
    for (int i = 0; t[i]; i++) 
        t2[i] = t[i];
    t2[count - 1] = c;  
    delete[] t;
    return t2;
}

int main()
try
{
    char *text = new char[0];
    char c;
    while (cin.get(c) && c != '!') //cin.get() for whitespaces preserving
            text = addchartotext(text, c);
    cout << text << endl;
    delete[] text;
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
