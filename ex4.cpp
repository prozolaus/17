#include "std_lib_facilities.h"

char *strdup(const char *cstr)
{
    if (cstr == nullptr)
        error("Nullptr was sent to strdup()");
    int n = 0, i = 0;
    while (true)
    {
        if (!cstr[i++])
            break;
        n++;
    }
    char *s = new char[n];
    for (int i = 0; i < n; i++)
        s[i] = cstr[i];
    return s;
}

int main()
try
{
    char hw[] = "Hello, World!";
    char *s = strdup(hw);
    cout << s << endl;
    delete[] s;
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
