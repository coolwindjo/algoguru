#include<stdio.h>
#define MAX_VERTEX 200
enum{RED=1, BLUE};
enum BOOL{FALSE, TRUE};

BOOL initGraph(FILE *fp); /* ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� �׷����� �ʱ�ȭ�ϴ� �Լ� */
void solve(int vNum, int col); /* DFS�� Ž���Ͽ� coloring�� �������� �˻� */
void outputGraph(); /* �׷������� ������ ������ ���踦 ���� ��� ���·� ��� �� */

int graph[MAX_VERTEX][MAX_VERTEX];	/* �������� ���� ���� ���� ���� ��� �迭 */
int color[MAX_VERTEX];	/* ������ �÷� �� ���� */
BOOL colorable;			/* binary coloring�� �����ϸ� TRUE, �ƴϸ� FALSE */
int vertexCnt, edgeCnt;	/* ���� ������ ���� ���� ���� ���� */
/*----------------------------------------------------------------------------------------
 �Լ��� : main()
----------------------------------------------------------------------------------------*/
int main()
{
	int i;
	FILE *fp;			/* �׷��� ���� ���� ������ ���������� */
	fp=fopen("d:\\data\\binaryColor.txt", "rt");
	if(fp==NULL){
		printf("File open error!\n");
		return 1;
	}

	while(initGraph(fp))
	{
		outputGraph();
		for(i=0; i<vertexCnt; ++i)
			color[i] = 0;   /* ������ color ������ ������ �迭 �ʱ�ȭ */
		colorable=TRUE;		/* binary coloring�� �������� �ʱ�ȭ */
		solve(0,RED);  /* 0�� ����, RED color�� ���̿켱 Ž�� ���� */

		if(colorable == 0)
			printf("Not BinaryColorable.\n\n");
		else
			printf("BinaryColorable.\n\n");
	}
	fclose(fp);
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: initGraph() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� �׷����� �ʱ�ȭ�ϴ� �Լ�
Parameters		: fp - �׷��� ������ �����ϰ� �ִ� ������ ���� ������
Returns			: �׷��� �� ��Ʈ�� ���������� �ʱ�ȭ �ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL initGraph(FILE *fp)
{
	int vertex1, vertex2;  /* �������� �Է��� ���� ���� */
	int i,j;       /* iterator */

	fscanf(fp, "%d %d\n", &vertexCnt, &edgeCnt);  /* ������ ������ ������ �б� */

	if(vertexCnt==0 && edgeCnt==0)
		return FALSE;  /* �׷��� ������ �б⸦ �����ϸ� false ���� */

	/* ������ ������ ���� ���� ��� ���� �ʱ�ȭ */
	for(i=0; i<vertexCnt; ++i)
		for(j=0; j<vertexCnt; ++j)
				graph[i][j] = 0;


	/* ������ �׷��������� ��Ī��(Symmetry) ������ �ʱ�ȭ ǥ�� */
	for(i=0; i<edgeCnt; ++i)
	{
		fscanf(fp, "%d %d\n", &vertex1, &vertex2);
		graph[vertex1][vertex2] = graph[vertex2][vertex1] = 1;
	}
	return TRUE;  /* ���������� �׷��� �����͸� �о����� true ���� */
}
/*--------------------------------------------------------------------------------------
Function name 	: outputGraph() - �׷������� ������ ������ ���踦 ���� ��� ���·� ��� ��
Parameters		: ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void outputGraph()
{
	int i,j;         /* iterator */

	/* ������ ���ι��� ��� */
	printf("   ");
	for(i=0; i<vertexCnt; ++i)
		printf("%3d",i);

	printf("\n");

	for(i=0; i<vertexCnt; ++i)
	{
		printf("%3d",  i);
		for(j=0; j<vertexCnt; j++)
				printf("%3d", graph[i][j]);
		printf("\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: solve() - dfs�� Ž���Ͽ� coloring�� �������� �˻�
Parameters		: vNum - ���� ��ȣ
             	  col - ������ color ��
Returns			: ����
--------------------------------------------------------------------------------------*/
void solve(int vNum, int col)
{
	// TODO
	return;
}
