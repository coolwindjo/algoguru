#include<stdio.h>
#include "circularQueue.h"
#define NL printf("\n")
#define MAX_SIZE 100  /* �̷� row, column�� �ִ� ũ�� */

int map[MAX_SIZE + 1][MAX_SIZE  + 1];  /* �̷� ������ ������ �迭(0��, 0�� ��� ����) */
int row, col;     /* map�� ����(row), ����(column)�� ũ�� ���� ���� */
RC  start, goal;  /* �̷��� ������ǥ, ������ǥ ���� */

BOOL dataLoad(const char *fileName); /*  ������ ���Ͽ��� �˻��� �����͸� �Է� �޾� map�� �����ϴ� �Լ� */
int solve(); /* �ʺ� �켱Ž��(BFS)������� �ִܰŸ� ���ϴ� �Լ� */
void output(); /* �̷� ���� ����Լ� */
BOOL inRange(int r, int c); /* row, column�� ���ռ� �Ǻ� �Լ� */

/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	const char *fileName[] = { "d:\\data\\�̷�ã��1.txt" , "d:\\data\\�̷�ã��2.txt",
								"d:\\data\\�̷�ã��3.txt" };
	size_t i;
	int res;
	for (i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		if (dataLoad(fileName[i]) == FALSE) return 0;
		res = solve();
		if (res > 0) {
			printf("�ִ� �Ÿ� : %d\n\n", res);
		}
		else {
			printf("������ �� �����ϴ�.\n\n");
		}
		
		output();
		NL;
		printf("===================================================================\n\n");
		getchar();
	}
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: dataLoad() - ������ ���Ͽ��� �˻��� �����͸� �Է� �޾� map�� �����ϴ� �Լ�
Parameters		: char *fileName - �̷� ������ ����� ������ ���ϸ�
Returns			: ���� �бⰡ �����ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dataLoad(const char *fileName){
	FILE *fp;
	int i,j; /* iterator */
	char ch;
	fp = fopen(fileName, "rt");
	if (fp == NULL) {
		printf("file open error!!!\n"); 	getchar();
		return FALSE;
	}
	if (fscanf(fp, "%d %d\n", &row, &col) != 2) return FALSE;
	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			ch = fgetc(fp);   /* fp���Ϸ� ���� �� ���� �Է� ���� */
			if (ch == '#') map[i][j] = -1;   /* �Է� ���� ���ڰ� �� �̸� */
			else if (ch == '.') map[i][j] = -2; /* �Է� ���� ���ڰ� �� �̸� */
			else if (ch == 'S') {  /* �Է� ���� ���ڰ� ������ġ �̸� */
				map[i][j] = 0;
				start.row = i; start.col = j; 
			}
			else if (ch == 'G') {  /* �Է� ���� ���ڰ� ������ġ �̸� */
				map[i][j] = -2;    /* goal�� ���ڸ� ��(.)�� ���� */
				goal.row = i;	goal.col = j;
			}
		}
		fgetc(fp);  /* ���� ���� \n(���๮��)�� �о ���� */
	}
	fclose(fp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name 	: output() - �̷� ���� ����Լ�
Parameters		: ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void output()
{
	int i, j;
	printf("** �̷���� **\n");
	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			if(map[i][j]==-1)	printf("  #");        
			else if (map[i][j] == -2) printf("  .");  
			else if(map[i][j] == 0) printf("  S");
			else printf("%3d", map[i][j]);
		}
		NL;
	}
	NL;
}
/*--------------------------------------------------------------------------------------
Function name 	: solve() - bfs������� �ִܰŸ� ���ϴ� �Լ�
Parameters		: ����
Returns			: �ִܰŸ� ��
--------------------------------------------------------------------------------------*/
int solve()
{
	// TODO
	return 0; // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: inRange() - row, colum�� ���ռ� �Ǻ� �Լ�
Parameters		: int r - �� ��
  	  	  	  	  int c - �� ��
Returns			: ������ �����̸� TRUE ����, �������� �����̸� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL inRange(int r, int c)
{
	if((0<r && r <= row) && (0<c && c <= col))
		return TRUE;
	else
		return FALSE;
}

