
/* [�ۼ� ����] */
/* 1. �׽�Ʈ ���̽��� �Ʒ� �迭�� �߰��Ͻÿ� ������ 8�� ����. �迭�� �̸��� ���� �Ұ��� */
/* 2. �׽�Ʈ ���̽� �迭 ���� : { �̼�����������1, ..., �̼�����������8 } */
/* ���� ���, { 101, 101, 100, 50, 30, 51, 75, 100 }�� */
/* �̼������������� 101, 101, 100, 50, 30, 51, 75, 100 ������ �������� �ǹ��Ѵ�. */
int testInput_example[8] = { 101, 101, 100, 50, 30, 51, 75, 100 };

int testInput_1_1[8] = { 30, 50, 60, 110, 60, 110, 60, 110/*[FIXME]*/, }; // TODO: �׸� 1-1 �׽�Ʈ �Է��� �߰��Ͻÿ�.
int testInput_1_2[8] = { 30, 50, 60, 60, 110, 110, 60, 40/*[FIXME]*/, }; // TODO: �׸� 1-2 �׽�Ʈ �Է��� �߰��Ͻÿ�.
int testInput_1_3[8] = { 30, 110, 50, 50, 110, 110, 60, 110/*[FIXME]*/, }; // TODO: �׸� 1-3 �׽�Ʈ �Է��� �߰��Ͻÿ�.




#include "./lib/device.h"
/* device.h���� �뷫������ �Ʒ��� ���� ������ �Լ��� ���ǰ� �ִ�.
 * ���� ������̹Ƿ� �� �ּ��� Ǯ� �Ʒ� �ڵ带 ����ؼ��� �ȵȴ�.  (device.h�� ���Ե� ������)
 * �Ʒ� �ּ��� �����Ͽ� ����ϴ� ��� ���������� �������� �ʴ´�.


/*
 *  ���� �������� ������ �̼����� �������� ��ȯ�ϴ� �������̽�
 *
int getCurrentPM(); 

/*
 * �ٶ� ����� ���� ���Ϸ� ����Ͽ� ������ �ٶ� ���⸦ ��ȯ (�׽�Ʈ ���)
 *
int determineWindStrength()
{
	int pm = getCurrentPM(); //�̼������������� getCurrentPM()�Լ��� ȣ���ؼ� ��´�.
	
	int polutionLevel = mapToPolutionLevel(pm); // �̼���������_����_������
	int result = mapToWindStrength(polutionLevel); // ��������_����_�ٶ�����

	if (isTurboModeBeginCondition(polutionLevel))
		turboMode = TRUE;
	else if (isTurboModeEndCondition(polutionLevel))
		turboMode = FALSE;
		
	if (turboMode)
		result = TURBO_MODE;
	
	totalLoad += getLoadOf(result); // �ٶ� ���⿡ ���� ���Ϸ��� ����Ͽ� ����
	
	return result;
}
*/



int count = 0;
int* fakeDust;

int getCurrentPM()
{
	// TODO: ���ϴ� �̼������������� ������ �� �ֵ��� fake/stub�� �����Ͻÿ�.

	return fakeDust[count++]; // FIXME: �ʿ��� �ڵ�� ��ü�Ͻÿ�.
}


void test_2_1()
{
	// TODO: �׸� 2-1. 
	// �̼� ���� �ܰ谡 (�ſ� ����, �ſ� ����, ����, ����, ����, ����, ����) ������ 7���� �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
	int input[] = { 110, 110, 60, 40, 60, 60, 60 };
	fakeDust = input;
	count = 0;
	for (int i = 0; i < 7; ++i)
		determineWindStrength();
}

void test_2_2()
{
	// TODO: �׸� 2-2. 
	// �� ���� �ܰ谡 (�ſ� ����, ����, ����, �ſ� ����, ����, ����, ����, �ſ� ����, ����, �ſ� ����, ����) ������ 11���� �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
	int input[] = { 110, 60, 60, 110, 60, 20, 60, 110, 60, 110, 60 };
	//int input[] = { 111, 70, 70, 70, 110, 10, 70, 170, 70, 110, 70 };  // ���� ���� ó���Ǵ� ������ �־���
	fakeDust = input;
	count = 0;
	for (int i = 0; i < 11; ++i)
		determineWindStrength();
}


/* main �Լ��� �ۼ��� �׽�Ʈ ���̽� �������� */
/* �ʿ信 ���� ������� �����Ͼ ������ */
/* main �Լ��� ä���� ������ */


int main()
{
	printTestResults();  // testInput�� ����� �׽�Ʈ �Է����� ������ ����� ������ش�. (������ Ȯ�ο�)

	test_2_1();

	test_2_2();

	return 0;
}