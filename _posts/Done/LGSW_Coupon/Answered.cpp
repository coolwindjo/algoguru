#if 1
#define TEST
#endif // 1
#define TEST1

// #include "../../ProbSolvStart.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N; // 이벤트 기간(일)
int M; // 윤대리가 가진 돈
int P[1000 + 10]; // 음식 가격
int C[1000 + 10]; // 배달비

int sol_cnt; // 주문 가능한 최대 횟수
int sol_r; // 남은 돈의 최대값

#define W_IFNOT(cond) WarnIfNot((cond), (#cond))
#define P_IFNOT(cond, var) if (!W_IFNOT(cond)) cout << "= " << var <<endl;

#define FOR_INC(i, from, to) for (int (i)=(from); (i)<(to); ++(i))
#define FOR(i, to) FOR_INC((i), 0, (to))

void InputData(void)
{
	int i;

	cin >> i;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> P[i] >> C[i];
	}
}

void OutputData(void)
{
	cout << sol_cnt << endl;
	cout << sol_r << endl;
}

void Sort(void)
{
	int i, j;

	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (P[i] + C[i] > P[j] + C[j]) { // Pi와 Ci의 합을 기준으로 오름차순 정렬
				int t = P[i];
				P[i] = P[j];
				P[j] = t;
				t = C[i];
				C[i] = C[j];
				C[j] = t;
			}
		}
	}
}

typedef pair<int, int> ii;

void calCntRem(vector<ii>& vPC, int& r, int& cnt){
	for (int i = 0; i < N; i++) {
		r -= vPC[i].first + vPC[i].second;
		if(r < 0) {
			r += vPC[i].first + vPC[i].second;
			break;
		}
		cnt++;
	}
}

void Sol(vector<ii>& vPC, int& r, int& cnt) {
	sort(begin(vPC), end(vPC), [](const ii& a, const ii& b){
		return (a.first+a.second) < (b.first+b.second);
	});

	r = M;
	calCntRem(vPC, r, cnt);
}

void Solve(void)
{
	vector<ii> vPC;
	FOR(i, N) {
		vPC.push_back(ii(P[i], C[i]));
	}

	sort(begin(vPC), end(vPC), [](const ii& a, const ii& b){
		return (a.first+a.second) < (b.first+b.second);
	});
	
	vector<ii> vP;
	FOR(k, N) {
		vP.push_back(ii(-1*P[k], k));
	}
	sort(begin(vP), end(vP));
	
#ifdef TEST
	cout << "P: ";
	FOR(k, N) {
		cout << vPC[k].first << ", ";
	}
	cout <<endl;
	cout << "C: ";
	FOR(k, N) {
		cout << vPC[k].second << ", ";
	}
	cout <<endl;
#endif
	
	int maxR = 0;
	int maxCnt = 0;
	FOR(i, N) {		
		vector<ii> cvPC(vPC);
		int r = M;
		int cnt = 0;
		int idx = vP[i].second;
		int orgP = cvPC[idx].first;
		cvPC[idx] = ii(orgP * 0.5, cvPC[idx].second);
		
#ifdef TES
		cout << idx << ":"<< cvPC[idx].first <<"," << cvPC[idx].second <<endl;
#endif

		
		Sol(cvPC, r, cnt);

#ifdef TES
		cout << idx << "="<< cvPC[idx].first <<"," << cvPC[idx].second <<endl;
#endif
		
		if (cnt > maxCnt) {
			maxCnt = cnt;
			maxR = r;
		}
		else if (cnt == maxCnt) {
			if (r > maxR) {
					
#ifdef TEST
	cout << "P: ";
	FOR(k, N) {
		cout << cvPC[k].first << ", ";
	}
	cout <<endl;
	cout << "C: ";
	FOR(k, N) {
		cout << cvPC[k].second << ", ";
	}
	cout <<endl;
#endif
				maxR = r;				
			}
		}
		else {}
	}
	
	sol_r = maxR;
	sol_cnt = maxCnt;
}

int main(void)
{
	InputData(); // 입력

	Solve(); // 문제 해결

	OutputData(); // 출력

	return 0;
}

