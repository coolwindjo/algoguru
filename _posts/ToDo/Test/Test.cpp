#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1")
#endif

template <class T> void f(T &i) { std::cout << 1 << std::endl; }
template <> void f(const int &i) { std::cout << 2 << std::endl; }

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    std::cout << "Ans:";
    int i = 42;
    f(i);
    return 0;
}
