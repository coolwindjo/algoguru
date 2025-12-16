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
    string s_;
public:
    ProbSolv()
    {
        string line;
        FOR (i, 2) {
            getline(cin, line);
            if (line.length() > 2) {
                break;
            }
        }
        for (auto c : line) {
            if (c == '\"') continue;
            s_.push_back(c);
        }
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << boolalpha << isPalindrome(s_);
    } // _Solve()

    bool isPalindrome(string s) {
        string p;
        for (auto c : s) {
            if (c >='A' && c <= 'Z') p.push_back(c-'A'+'a');
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) p.push_back(c);
            else continue;
        }
        const int p_size = p.size();
        const int loop = static_cast<int>(p_size*0.5);
        for (int i=0; i<loop; ++i) {
            if (p[i] == p[p_size-1-i]) continue;
            else return false;
        }
        return true;
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
