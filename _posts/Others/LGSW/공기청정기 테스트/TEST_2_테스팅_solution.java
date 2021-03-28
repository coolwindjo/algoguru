import device.AirPurifier;
import device.ParticleSensor;
import device.TestUtils;

// �׽�Ʈ ����� �Ʒ� �ּ��� ���� �����Ǿ� �ִ�. 
// �ʿ��� ��� �Ʒ� �ּ��� ������ �����Ͽ� LedTest class�� �׽�Ʈ �Է°� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�. 
// NOTE: �׽�Ʈ ��� �ڵ�� ���忡 �̹� ���ԵǾ� ������ �Ʒ� �ּ��� �����Ͽ� ������� ���ÿ�.

/**
 * ParticleSensor.java
 * ���� �������� ������ �̼����� �������� ��ȯ�ϴ� �������̽�
 *
package device;

public interface ParticleSensor {
 	**
	 * @return ���� �������� ������ �̼����� ������
	 *
	int getcurrentPM();
}
*/

/**
 * AirPurifier.java
 * ���� û���⸦ ���� (�׽�Ʈ ���)
 * 
package device;

...

public class AirPurifier {
	...
	private ParticleSensor sensor;
	private boolean turboMode = false;
	private int totalLoad = 0;
	
	public AirPurifier(ParticleSensor sensor) {
		this.sensor = sensor;
		...
	}

	**
	 * �ٶ� ����� ���� ���Ϸ� ����Ͽ� ������ �ٶ� ���⸦ ��ȯ (�׽�Ʈ ���)
	 *
	public WindStrength determineWindStrength() {
		int pm = sensor.getCurrentPM();

		PolutionLevel polutionLevel = mapToPolutionLevel(pm); // �̼���������_����_������
		WindStrength result = mapToWindStrength(polutionLevel); // ��������_����_�ٶ�����
	
		if (isTurboModeBeginCondition(polutionLevel))
			turboMode_ = true;
		else if (isTurboModeEndCondition(polutionLevel))
			turboMode_ = false;
		
		if (turboMode_)
			result = TURBO_MODE;
	
		totalLoad_ += getLoadOf(result); // �ٶ� ���⿡ ���� ���Ϸ��� ����Ͽ� ����
		
		return result;
	}
	...
}
*/


public class AirPurifierTest {
	
	/* [�ۼ� ����] */
	/* 1. �׽�Ʈ ���̽��� �Ʒ� �迭�� �߰��Ͻÿ� ������ 8�� ����. �迭�� �̸��� ���� �Ұ��� */
	/* 2. �׽�Ʈ ���̽� �迭 ���� : { �̼�����������1, ..., �̼�����������8 } */
	/* ���� ���, { 101, 101, 100, 50, 30, 51, 75, 100 }�� */
	/* �̼������������� 101, 101, 100, 50, 30, 51, 75, 100 ������ �������� �ǹ��Ѵ�. */
	
	public int[] testInputSample = { 101, 101, 100, 50, 30, 51, 75, 100 };
	public int[] testInput_1_1 = {30, 50, 60, 110, 60, 110, 60, 110};
	public int[] testInput_1_2 = {30, 50, 60, 60, 110, 110, 60, 40};
	public int[] testInput_1_3 = {30, 110, 50, 50, 110, 110, 60, 110};
	
	public void test_2_1() {
		// TODO: �׸� 2-1. 
		// �̼� ���� �ܰ谡 (�ſ� ����, �ſ� ����, ����, ����, ����, ����, ����) ������ 7���� �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
		AirPurifier device = new AirPurifier(new ParticleSensor() {
			
			private int count = 0;
			private int[] fakePM = {110, 130, 60, 40, 60, 60, 60};

			@Override
			public int getcurrentPM() {
				// TODO Auto-generated method stub
				return fakePM[count++];
			}
		});
		
		for (int i = 0; i < 7; ++i)
			device.determineWindStrength();
	}

	public void test_2_2() {
		// TODO: �׸� 2-2. 
		// �� ���� �ܰ谡 (�ſ� ����, ����, ����, �ſ� ����, ����, ����, ����, �ſ� ����, ����, �ſ� ����, ����) ������ 11���� �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
		AirPurifier device = new AirPurifier(new ParticleSensor() {
			
			private int count = 0;
			private int[] fakePM = {110, 60, 60, 110, 60, 10, 60, 140, 60, 160, 60};

			@Override
			public int getcurrentPM() {
				// TODO Auto-generated method stub
				return fakePM[count++];
			}
		});
		
		for (int i = 0; i < 11; ++i)
			device.determineWindStrength();
	}

	// ��������� �����ϰ� ���� �ڵ尡 �ִٸ� �Ʒ� main()�� �ۼ��Ͽ� Ȱ���� �� �ִ�.
	// main �Լ��� �ڵ�� ä���� ������ ����.
	public static void main(String[] args) {
		 //printTestResult��  testInput�� ������ �׽�Ʈ �Է����� ������ ����� ȭ�鿡 ������ش�.
		AirPurifierTest runner = new AirPurifierTest();
		TestUtils.printTestResult(runner.testInputSample);
		TestUtils.printTestResult(runner.testInput_1_1);
		TestUtils.printTestResult(runner.testInput_1_2);
		TestUtils.printTestResult(runner.testInput_1_3);
		
		runner.test_2_1();
		runner.test_2_2();
	}
}
