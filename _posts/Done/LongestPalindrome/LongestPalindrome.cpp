#if 0
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1")
#endif

class ProbSolv
{
    string line_;
public:
    ProbSolv()
    {
        FOR(i, 10) {
            std::getline(std::cin, line_);
            if (line_.length() > 0) {
                break;
            }
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << longestPalindrome(line_);
    } // _Solve()

    int longestPalindrome(string s) {
#ifdef TEST
        cout << s ;
#endif  // TEST
        unordered_map<char, int> hashMap;
        for (char c : s) {
            hashMap[c]++;
        }
        int oneside = 0;
        int addOne = 0;
        FOR(i, hashMap.size()) {
            const char c = 'a' + i;
            const int num = hashMap[c];
            const int half = static_cast<int>(num/2);
            if (half > 0) oneside += half;
            if (num%2 > 0) addOne = 1;
        }
        return (2*oneside + addOne);
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
