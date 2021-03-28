#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quickSort(int *ary, int size);
void output(int *ary, int size);
void initArray(int *ary, int n);

int main()
{
	int dataList[10000];


	int startTime, endTime;
	int size = sizeof(dataList) / sizeof(dataList[0]);

	srand((unsigned int)time(NULL));

	initArray(dataList, size);

	startTime = clock();
	quickSort(dataList, size); 	/* �� ���� �Լ� ȣ�� */
	endTime = clock();
	printf("\n\n[ �� ����  �� ��� ]\n");
	output(dataList, size);
	printf("����Ʈ �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime-startTime));

	getchar();
	startTime = clock();
	quickSort(dataList, size); 	/* �� ���� �Լ� ȣ�� */
	endTime = clock();
	printf("\n\n[ �� ����  �� ��� ]\n");
	output(dataList, size);
	printf("����Ʈ �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime-startTime));
	getchar();
	return 0;
}
/*----------------------------------------------------------------------
�Լ��� �� ��� : quickSort() - �� ���� �Լ�
��������: ary - ������ ������ �迭�� �����ּ�
size - ��Ʈ�� �������� ����
���ϰ�: ����
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j;

	if(size<=1) return; // �������� 1�����̸� sort�� �Ϸ�� �� �̹Ƿ� return

	pivot = ary[size-1];

	// TODO

	// ���� �ұ����� ���� �� ���� ��� ȣ��
	// ���� �ұ����� ���� �� ���� ��� ȣ��
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : output() - �迭�� ��� ���� ����ϱ�
��������: ary - ������ ������ �迭�� �����ּ�
size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void output(int *ary, int size)
{
	for(int i=0; i<size; i++)
	{
		printf(" %d ", ary[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : initArray() - �迭�� ���Ҹ� ������ �ʱ�ȭ
��������: ary - �ʱ�ȭ�� ������ �迭�� �����ּ�
size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void initArray(int *ary, int n)
{
	int i;
	for(i=0; i<n; ++i)
		ary[i] = rand() % 1000 + 1;
}
