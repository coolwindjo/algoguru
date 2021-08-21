#if 1
#define TEST
#endif // 1
#define TEST1

/*
4
2 1 1 4
1 2 1 1
1 1 1 1
2 1 3 3
4

5
7 7 7 7 2
2 2 2 2 5
5 6 2 2 1
6 1 4 3 5
6 6 6 3 6
3
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define FOR_INC(i, from, to) for (int (i)=(from); (i)<(to); ++(i))
#define FOR(i, to) FOR_INC((i), 0, (to))
	
static const int WarnIfNot(const int condFlag, const char* condition){
 	if (condFlag == 0) {
        cout << "Warning: [" << condition << "] is violated!\n";
    }
    return condFlag;
}
#define W_IFNOT(cond) WarnIfNot((cond), (#cond))
#define P_IFNOT(cond, var) if (!W_IFNOT(cond)) cout << "= " << var <<endl;
#define OOR(x, min, max) (((x) < (min) || (x) > (max)))

#define MAXN (100)
int N;//크기
int sol;
int g_map[MAXN + 10][MAXN + 10];//지역높이 정보

typedef enum {
	eR=0, eD,
    eL, eU,
	eRD, eDL,
	eLU, eUR,
    eDIR_LEN
} Dir_e;
constexpr int DIR[eDIR_LEN][2] = {
    {0,1}, {1,0},
    {0,-1}, {-1,0},
    {1,1}, {1,-1},
    {-1,-1}, {-1,1}
};

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
constexpr int INF = 987654321;  // INF < 1e9 < 2e30 < INT_MAX

int g_max;
vvi g_grid;

void InputData() {
	int r, c;
	cin >> N;
	for (r = 0; r < N; r++) {
		vi rowG;
		for (c = 0; c < N; c++)
		{
			int val;
			cin >> val;
			g_map[r][c] = val;
			rowG.push_back(val);
		}
		g_grid.push_back(rowG);
	}
	
}

bool visit(int& cnt, vvi& grid, const ii& pos) {
	if (!OOR(pos.first, 0, N)) return false;
	if (!OOR(pos.second, 0, N)) return false;

	if (grid[pos.first][pos.second] > 0) {
		grid[pos.first][pos.second] = -1*cnt;
		return true;
	}
	return false;
}

int countSafes(vvi grid, const int border) {
	vii tops;
	FOR(r, N) {
		FOR(c, N) {
			const int val = grid[r][c];
			if (val >= border) {
				tops.push_back(ii(r,c));
			}
		}
	}

	int cnt = 0;
	queue<ii> Q;
	FOR(i, tops.size()) {
		Q.push(tops[i]);
	}
	
	const int maxLoop = 10;
	for(int i=0;!Q.empty() && (i<maxLoop); ++i) {
		const ii pos = Q.front(); Q.pop();
		if (visit(cnt, grid, pos)) {
			cnt++;
			FOR(dir, eDIR_LEN) {
				const ii next = ii(pos.first+DIR[dir][0], pos.second+DIR[dir][1]);
				if (visit(cnt, grid, next)) {
					Q.push(next);
				}
			}
		}
	}
	
	return cnt;
}

int main() {

	InputData();//입력 함수

	// 코드를 작성하세요
	cout << countSafes(g_grid, 3);

	//출력
	cout << sol;
	return 0;
}
