---
title: LGSW Safe Places
layout: post
tags:
- cpp
- bfs
- std-unordered-set
- std-queue
- flood-fill

---

- Count the number of Safe places
- Return the maximum number of the counts;

### Source

```cpp

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

        typedef pair<int, ii> i_ii;
        queue<i_ii> i_iiQ;
        FOR (i, viiTops.size()) {
            i_iiQ.push(i_ii(i+1, viiTops[i]));
        }

        const int maxLoop = INF;
        for (int i=0; !i_iiQ.empty() && i<maxLoop; ++i) {
            const i_ii cnt_pos = i_iiQ.front(); i_iiQ.pop();
            const int cnt = cnt_pos.first;
            const ii pos = cnt_pos.second;
            if (Visit(grid, border, pos, cnt)) {
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

```

### GitHub

- [LGSW_SafePlaces](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/LGSW_SafePlaces>){:target="_blank"}

![LGSW_SafePlaces]({{ "/assets/img/posting/lgsw_safe_places.png" | relative_url }})
