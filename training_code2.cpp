#include "std_lib_facilities.h"

int main()
try
{
    double *pm = new double[5]{0, 1, 2, 3, 4};
    int *pi = new int;
    *pi = 8;
    cout << *pi << endl;
    cout << pm[2] << endl;
    cout << *(pm + 3) << endl;
    delete pi;
    delete[] pm;
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
