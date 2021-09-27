#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

class ProbSolv
{
    int m_n;
public:
    ProbSolv()
    {
        m_n = 0;
        cin >> m_n; cin.ignore();
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        vi viAns = countBits(m_n);
        cout << "[";
        for (auto ans : viAns) {
            cout << ans << ", ";
        }
        cout << "]";
    } // _Solve()

    vector<int> countBits(int n) {
        vi viAns;
        FOR (i, n+1) {
            const string bin = toBin(i);
            int sum = 0;
            FOR (j, bin.length()) {
                if ('1' == bin[j]) {
                    sum++;
                }
            }
            viAns.push_back(sum);
        }
        return viAns;
    }
    
    string toBin(const int n) {
        if (n == 1) return "1";
        if (n == 0) return "0";
        return toBin(n/2) + to_string(n%2);
    }

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
