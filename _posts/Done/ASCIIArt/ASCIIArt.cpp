#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"
#include <iomanip>

#if 0
#pragma GCC optimize("O2") 
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
        int L;
        cin >> L; cin.ignore();
        int H;
        cin >> H; cin.ignore();
        string T;
        getline(cin, T);

        const int N = T.length();

        vstr vstrWholeLines;
        for (int i = 0; i < H; i++) {
            string ROW;
            getline(cin, ROW);
            vstrWholeLines.push_back(ROW);
        }

        const int numLetters = ceil(vstrWholeLines.front().length() / L);

        vector<vstr> vvstrLetters(numLetters);

        for (string line : vstrWholeLines) {
            size_t prev = 0;
            FOR (i, numLetters) {
                vvstrLetters[i].push_back(line.substr(prev, L));
                prev += L;
            }
        }

        const int lastIdx = 'Z' - 'A' + 1;
        vi viAnsIdx;
        FOR (i, N) {
            int diff = 'a' - 'A';
            int idx = T[i]-'A';
            if (idx >= diff) idx -= diff;
            if (idx > (lastIdx) || idx < 0) idx = lastIdx;
            viAnsIdx.push_back(idx);
        }

        // Print answer
        FOR (j, H) {
            for (int i : viAnsIdx) {
                cout << setw(L) << left << vvstrLetters[i][j];
            }
            cout << "\n";
        }

    } // _Solve()

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    cin >> numTCs;
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        cout << "\n";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}