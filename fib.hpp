#ifndef FIB_HPP
#define FIB_HPP
#include <iostream>
#include <type_traits>
#include <array>
#include <cassert>
using namespace std;
namespace Fib{
namespace Fibimpl{
const int max = 99;
std::array<long long int, max+1> cache;
int cache_max = 0;
template<int N>
struct FIB_impl{
    static const long long int value = FIB_impl<N-1>::value + FIB_impl<N-2>::value;
    static void warmup(){
        cache[N] = value;
        FIB_impl<N-1>::warmup();
    }
    static void foo(){
    }
};
template<>
struct FIB_impl<0>{
    static const long long int value = 1;
};
template<>
struct FIB_impl<1>{
    static const long long int value = 1;
    static void warmup(){
    }
};
}
using namespace Fibimpl;
template<int N,class = typename std::enable_if<N<=max>::type >
struct FIB{
    static const long long int value = FIB_impl<N-1>::value + FIB_impl<N-2>::value;
    static void warmup(){
        if(N>cache_max){
            cache_max=N;
        }
        cache[0]=cache[1]=1;
        cache[N]=value;
        FIB_impl<N-1>::foo();
        FIB_impl<N-1>::warmup();
    }
};
long long int get(int n){
    assert(n<=cache_max);
    return cache[n];
}
}
#endif // FIB_HPP
