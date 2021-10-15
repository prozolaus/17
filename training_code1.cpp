#include "std_lib_facilities.h"

void sizes(char ch, int i, int *ptri)
{
    cout << sizeof(ch) << endl;
    cout << sizeof(i) << endl;
    cout << sizeof(ptri) << endl;
}

int main()
try
{
    int a = 0;
    int *ptra = &a;
    sizes('a', a, ptra);
    cout << ptra << endl;
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
