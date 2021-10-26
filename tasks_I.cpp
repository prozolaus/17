#include "std_lib_facilities.h"

/*
ostream &print_array10(ostream &os, int *a)
{
    if (a == nullptr)
        error("Nullptr");
    const int n = 10;
    for (int i = 0; i < n; i++)
        os << a[i] << ", ";
    os << endl;
    return os;
}
*/

ostream &print_vector(ostream &os, const vector<int> a)
{
    const int n = a.size();
    for (int i = 0; i < n; i++)
        os << a[i] << ", ";
    os << endl;
    return os;
}

int main()
try
{
    const int n = 10;
    vector<int> m;
    for (int i = 0; i < n; i++)
        m.push_back(100 + i);
    print_vector(cout, m);
    
    /*
    const int n = 10;
    int *m = new int[n];
    for (int i = 0; i < n; i++)
        m[i] = 100 + i;
    print_array10(cout, m);
    delete[] m;
    */
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
