import java.util.Scanner;

public class Main {

	int []a;				//	ī��޸� ���ڸ� �����ϴ� �迭
	int N;					//	ī�� ����
	int M;					//	����ǰ�뷮

	public int solve() {
		int sol=0;
		//	�Ʒ� �ڵ��� ������ �����ϼ���
		for (int i = 0; i < N - 3; i++){
			for (int j = i + 1; j < N - 2; j++){
				for (int k = j + 1; k < N - 1; k++){
					for (int l = k + 1; l < N; l++){
						if (a[i] + a[j] + a[k] + a[l] == M) sol++;
					}
				}
			}
		}
		return sol;
	}

	public void inputData()  {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();			//	ī�� ����	
		M = sc.nextInt();			//	����ǰ�뷮
		a = new int [N+1];		

		for(int i=0 ; i<N ; i++){
			a[i] = sc.nextInt();		//	ī�� �޸� ����
		}
	}

	public static void main(String[] args){
		Main m = new Main();

		m.inputData();					//	�Է� �Լ�
		int sol = m.solve();			//	���� Ǯ��
		System.out.println(sol);	//	���� ���
	}
}