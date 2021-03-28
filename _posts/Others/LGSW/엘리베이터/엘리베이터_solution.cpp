#include <iostream>
#include <stdlib.h>
using namespace std;

int N;	// �ǹ��� ����
int X[100+10]; // ���� �������� ��ġ
int Y[100+10]; // ���� �Һ����� ��ġ
 
typedef struct
{
	int xi, yi;
}LINE;
LINE C[100+10]; 

void InputData(void){
	cin >> N;
	for(int i=0; i<N; i++) cin >> X[i] >> Y[i];
}
int comp(const void * a, const void * b){
	LINE *p = (LINE*)a, *q = (LINE*)b;
	if(p->yi > q->yi)return 1;
	if(p->yi < q->yi)return -1;
	return 0;
}
int Solve(void){
	int low, sol = 1;
	for(int i=0; i<N; i++) {
		C[i].xi = X[i];
		C[i].yi = Y[i];
	}
	qsort(C, N, sizeof(C[0]), comp);
	low = C[0].yi;
	for(int i=1; i<N; i++){
		if(C[i].xi > low){
			  low = C[i].yi;
			  sol++;
		}
	}
	return sol;
}

int main(void){
	int ans;
	InputData(); // �Է��Լ�
	
	// �ڵ带 �ۼ��ϼ���
	ans = Solve();
	cout << ans << endl;
	
	return 0;
}