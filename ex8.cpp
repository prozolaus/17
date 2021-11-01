#include "std_lib_facilities.h"

int main()
try
{
    string text;
    char c;
    while (cin.get(c) && c != '!') //cin.get() for whitespaces preserving 
            text.push_back(c);
    cout << text << endl;
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
