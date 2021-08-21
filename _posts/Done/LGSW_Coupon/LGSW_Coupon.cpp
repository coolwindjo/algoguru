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
    int m_N;
    int m_M;
    vii m_viiPC;
public:
    ProbSolv()
    {
        cin >> m_N >> m_M; cin.ignore();
        FOR (i, m_N) {
            int p = 0;
            int c = 0;
            cin >> p >> c; cin.ignore();
            m_viiPC.push_back(ii(p,c));
        }
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){

        vii viiP(m_N);
        FOR (i, m_N) {
            viiP[i] = ii(-1*m_viiPC[i].first, i);
        }
        sort(begin(viiP), end(viiP));

        int maxCnt = 0;
        int maxRem = 0;
        FOR(i, m_N)
        {
            vii viiPC(m_viiPC);
            const int idx = viiP[i].second;
            const int price = viiPC[idx].first;
            viiPC[idx].first = static_cast<int>(price*0.5);

            Sort(viiPC);

#ifdef TEST
            cout << "Before:";
            Print(viiPC);
#endif

            int rem = m_M;
            const int cnt = CalCntRem(viiPC, rem);

            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxRem = rem;
#ifdef TEST
                cout << "OnGoing:";
                Print(viiPC);
                cout <<endl;
#endif
            }
            else if (cnt == maxCnt) {
                if (rem > maxRem) {
                    maxRem = rem;
#ifdef TEST
                    cout << "Updated:";
                    Print(viiPC);
                    cout <<endl;
#endif
                }
            }
            else {}
        }

        cout << maxCnt << " " << maxRem;
    } // _Solve()

    void Sort(vii& viiPC) {
        sort(begin(viiPC), end(viiPC), [](const ii& a, const ii& b){
            return ((a.first+a.second)<(b.first+b.second));
        });
    }

    int CalCntRem(const vii& viiPC, int& rem) {
        int cnt = 0;
        for (auto pc : viiPC) {
            const int cost = pc.first + pc.second;
            rem -= cost;
            if (rem < 0) {
                rem += cost;
                break;
            }
            cnt++;
        }
        return cnt;
    }

    void Print(const vii& viiPC) {
        cout << "\nP: ";
        FOR (j, m_N) {
            cout << viiPC[j].first <<",";
        }
        cout << "\nC: ";
        FOR (j, m_N) {
            cout << viiPC[j].second <<",";
        }
        cout <<endl;
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