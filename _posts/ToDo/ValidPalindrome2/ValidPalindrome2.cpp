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
    bool is_valid_;
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
        {
            CoolTimer t("DFS");
            cout << boolalpha << validPalindrome(s_);
        }
        {
            CoolTimer t("simple");
            cout << boolalpha << validPalindrome_simple(s_);
        }
    } // _Solve()

    bool validPalindrome(string s) {
        is_valid_ = false;
        DFS(s, 0, s.size()-1, 1);
        return is_valid_;
    }

    void DFS(const string &s, const int i, const int j, const int c) {
        if (i>=j) is_valid_ = true;
        if (is_valid_) return;
        if (s[i] == s[j]) DFS(s, i+1, j-1, c);
        else if (c > 0) {
            DFS(s, i+1, j, c-1);
            DFS(s, i, j-1, c-1);
        }
        else return;
    }

    bool validPalindrome_simple(string s) {
        const int s_size = s.size();
        int skipcnt = 1;
        int tmpi=0;
        int tmpj=0;
        for (int i=0, j=s_size-1-i, lim=65432; i<j &&lim ;--lim) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            }
            else if (skipcnt > 0){
                tmpi = i;
                tmpj = j;
                if (s[i+1] == s[j]) {
                    ++i;
                }
                else if (s[i] == s[j-1]) {
                    --j;
                }
                else return false;
                skipcnt--;
            }
            else if (skipcnt == 0) {
                i=tmpi;
                j=tmpj;
                --j;
                skipcnt--;
            }
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
