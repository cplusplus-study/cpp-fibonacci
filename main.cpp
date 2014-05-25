#include <iostream>
#include "fib.hpp"

using namespace std;

int main()
{
    static_assert(Fib::FIB<50>::value == 20365011074L, "wrong answer");
    Fib::FIB<50>::warmup();
    cout << "Hello World!" << endl;
    cout << Fib::get(50) << "\n";
    cout << Fib::get(51) << "\n";
    return 0;
}

