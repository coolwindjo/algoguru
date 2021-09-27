#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 1
#pragma GCC optimize("O1") 
#endif 

class ProbSolv
{
public:
    ProbSolv()
    {
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){

    } // _Solve()

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    cin >> numTCs; cin.ignore();
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}
