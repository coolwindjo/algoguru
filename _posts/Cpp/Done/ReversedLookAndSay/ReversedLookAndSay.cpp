#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
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
        string s;
        getline(cin, s); cin.ignore();
        string strToCheck;
        while (s.length() > 0) {
            strToCheck = revLAS(s);
            if (s.compare(strToCheck) == 0) break;
            if (s.compare(convLAS(strToCheck)) != 0) break;
            s = strToCheck;
        }
        cout << s;
    } // _Solve()

    string revLAS(const string& strLAS) {
        string ret("");
        int numVals = 0;
        for (auto c : strLAS) {
            if (0 == numVals) {
                numVals = c - '0';
                continue;
            }
            string strVals(numVals, c);
            ret += strVals;
            numVals = 0;
        }
        return ret;
    }

    string convLAS(const string& str) {
        string ret("");
        for (auto it = begin(str); it != end(str);) {
            auto itLast = find_if_not(next(it), end(str), [it](auto& s){
                return (s == *it);
            });
            ret += to_string(distance(it, itLast));
            ret += *it;
            it = itLast;
        }
        return ret;
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