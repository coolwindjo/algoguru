#include <stdio.h>
#include <stdlib.h> 
int N;	// �ǹ��� ����
int X[100+10]; // ���� �������� ��ġ
int Y[100+10]; // ���� �Һ����� ��ġ
 
typedef struct
{
	int xi, yi;
}LINE;
LINE C[100+10]; 
void InputData(void){
	int i;
	scanf("%d", &N);
	for(i=0; i<N; i++) scanf("%d %d", &X[i], &Y[i]);
}
int comp(const void * a, const void * b){
	LINE *p = (LINE*)a, *q = (LINE*)b;
	if(p->yi > q->yi)return 1;
	if(p->yi < q->yi)return -1;
	return 0;
}
int Solve(void){
	int i, low, sol = 1;
	for(i=0; i<N; i++) {
		C[i].xi = X[i];
		C[i].yi = Y[i];
	}
	qsort(C, N, sizeof(C[0]), comp);
	low = C[0].yi;
	for(i=1; i<N; i++){
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
	printf("%d\n",ans);
	
	return 0;
}