#include "std_lib_facilities.h"

void stack_check()
{
    int x = 7;
    cout << "Stack: " << &x << '\n';
}

void double_stack()
{
    int x = 0;
    cout << "Stack: " << &x << '\n';

    int y = 10;
    cout << "Stack: " << &y << '\n';
}

void free_check()
{
    int *arr = new int[5];

    for (int i = 0; i < 5; ++i)
        cout << "Free: " << &arr[i] << '\n';

    delete[] arr;
}

int main()
try
{
    //Free store address grow upwards and stack addresses grow down!
    stack_check();
    double_stack();
    free_check();
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
