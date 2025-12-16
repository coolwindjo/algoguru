#if 0
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

typedef enum {
	eR=0, eD,
    eL, eU,
    eRD, eDL, eLU, eUR,
    eDIR_LEN
} Dir_e;
constexpr int DIR[eDIR_LEN][2] = {
    {0,1}, {1,0},
    {0,-1}, {-1,0},
    {1,1}, {1,-1},
    {-1,-1}, {-1,1}
};

class ProbSolv
{
    int m_N;
    vvi m_grid;
    int m_max;
public:
    ProbSolv()
    {
        cin >> m_N;

        m_max = 0;
        FOR(i, m_N){
            vi rowG;
            FOR(j, m_N){
                int val;
                cin >> val;
                if (val > m_max) {
                    m_max = val;
                }
                rowG.push_back(val);
            }
            m_grid.push_back(rowG);
        }
#ifdef TEST
        PrintGrid(m_grid);
#endif
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){

        int maxSafePls = 0;
        FOR_DEC(border, 0, m_max+1) {
            const int numSafePls = CountSafePls(m_grid, border);
            if (numSafePls > maxSafePls) {
                maxSafePls = numSafePls;
            }
        }
        cout << maxSafePls;

    } // _Solve()

    int CountSafePls(vvi grid, const int border) {
        vii viiTops = PickStartingPts(grid, border);
#ifdef TEST
        for (auto top : viiTops) {
            cout << top.first << "," << top.second << " - ";
        }
        cout << endl;
#endif

        typedef pair<int, ii> i_ii;
        queue<i_ii> i_iiQ;
        FOR (i, viiTops.size()) {
            i_iiQ.push(i_ii(i+1, viiTops[i]));
        }

#ifdef TEST
        queue<i_ii> prQ(i_iiQ);
        while(!prQ.empty()) {
            const auto& pos = prQ.front(); prQ.pop();
            cout << pos.first << ":" << pos.second.first << "," << pos.second.second << " - ";
        }
        cout << endl;
#endif
        const int maxLoop = INF;
        for (int i=0; !i_iiQ.empty() && i<maxLoop; ++i) {
            const i_ii cnt_pos = i_iiQ.front(); i_iiQ.pop();
            const int cnt = cnt_pos.first;
            const ii pos = cnt_pos.second;
            if (Visit(grid, border, pos, cnt)) {
#ifdef TEST
                PrintGrid(grid);
#endif
                FOR (dir, eDIR_LEN) {
                    const ii nextPos = ii(  pos.first + DIR[dir][0],
                                            pos.second + DIR[dir][1]);
                    if (OOR(nextPos.first, 0, m_N-1)) { continue; }
                    if (OOR(nextPos.second, 0, m_N-1)) { continue; }
                    const int val = grid[nextPos.first][nextPos.second];
                    if (val <= -1*cnt) { continue; }
                    i_iiQ.push(i_ii(cnt, nextPos));
                }
            }
        }

        unordered_set<int> hashCnt;
        FOR (r, m_N) {
            FOR (c, m_N) {
                const int val = grid[r][c];
                if (val < 0) {
                    hashCnt.insert(val);
                }
            }
        }

#ifdef TEST
                PrintGrid(grid);
#endif

        return hashCnt.size();
    }

    bool Visit(vvi& grid, const int border, const ii& pos, const int cnt) {
        if (OOR(pos.first, 0, m_N)) return false;
        if (OOR(pos.second, 0, m_N)) return false;
        const int val = grid[pos.first][pos.second];
        if (val >= border) {
            grid[pos.first][pos.second] = -1*cnt;
            return true;
        }
        else if ((val < 0) && (val > -1*cnt)) {
            // Update with smaller value (bigger count)
            grid[pos.first][pos.second] = -1*cnt;
            return true;
        }
        else if (val <= -1*cnt) {
            return false;
        }
        else {}
    }

    vii PickStartingPts(const vvi& grid, const int border) {
        vii viiTops;
        FOR (r, m_N) {
            FOR (c, m_N) {
                const int val = grid[r][c];
                if (val >= border) {
                    viiTops.push_back(ii(r,c));
                }
            }
        }
        return viiTops;
    }

    void PrintGrid(const vvi& grid) {
        cout <<endl;
        FOR(i, m_N){
            FOR(j, m_N){
                cout << setw(3) << grid[i][j] << " ";
            }
            cout <<endl;
        }
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