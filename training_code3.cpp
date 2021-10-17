#include "std_lib_facilities.h"

class Test
{
private:
    int sz;
    double *elem;

public:
    Test(int s);
    int size() const { return sz; }
    ~Test();
};

Test::Test(int s)
    : sz{s},
      elem{new double[s]}
{
    cout << "Constructor" << endl;
    for (int i = 0; i < s; i++)
        elem[i] = 0;
}

Test::~Test()
{
    cout << "Destructor" << endl;
    delete[] elem;
}

int main()
try
{
    Test test1{4}, test2{5};
    cout << test1.size() << endl;
    cout << test2.size() << endl;
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
