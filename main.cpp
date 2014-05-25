#include <iostream>
#include "fib.hpp"

using namespace std;

int main()
{
    assert(Fib::get(50)== 20365011074L);
    cout << "Hello World!" << endl;
    cout << Fib::get(50) << "\n";
    cout << Fib::get(51) << "\n";
    return 0;
}

