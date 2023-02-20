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
        string msg;
        getline(cin, msg);

        vector<bool> bits;
        for (auto c : msg) {
            auto binary = toBinStr(c, 7);
            copy(begin(binary), end(binary), back_inserter(bits));
        }

        unordered_map <bool, string> toZeros {
            {false, "00 "},
            {true, "0 "}
        };

        for (auto it = begin(bits); it != end(bits);) {
            const bool curr = *it;
            auto itLast = find(next(it), end(bits), !curr);
            if (it != begin(bits)) cout << " ";
            cout << toZeros[*it] << string (distance(it, itLast), '0');
            it = itLast;
        }
    } // _Solve()

    vector<bool> DFS(const int n, const int r) {
        if (n <= 0) { return {}; }
        vector<bool> ret = DFS(n/r, r);
        ret.push_back(n%r);
        return ret;
    }

    vector<bool> toBinStr(const int n, const int disp) {
        vector<bool> bits = DFS(n, 2);
        int numSp = disp - bits.size();
        vector<bool> ret(numSp, false);
        copy(begin(bits), end(bits), back_inserter(ret));
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