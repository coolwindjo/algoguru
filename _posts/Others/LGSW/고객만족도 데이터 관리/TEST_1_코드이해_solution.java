import java.util.Scanner;

public class Main {
	
	int M;		// �ݺ� ���� ȸ��
	char[] S;	// ���� ���ڿ�
	
	void inputData() {

		Scanner sc = new Scanner(System.in);
		
		M = sc.nextInt();
		S = (sc.next() + "\0").toCharArray();	
		
		sc.close();
	}

	void print_short(char c, int cnt) {
		System.out.printf("%c(%d)", c, cnt);
	}

	void print_raw(char c, int cnt) {
		int i;
		for (i = 0; i < cnt; i++) {
			System.out.printf("%c", c);
		}
	}

	void Solve() {
		int i;			// ���ڿ� S�� � ���ڸ� ����
		int len;		// ���ڿ� S�� ����
		char r_char;	// �ݺ��Ǵ� ����
		int r_cnt;		// �ݺ� ȸ��
		
		// �ڵ� ���� �� ��� ���
		
		// ���� ���ڿ��� ���� len�� ���
		len = S.length;

		// ���ڿ��� ù ���� ó��
		r_char = S[0];
		r_cnt = 1;

		// ���ڿ��� ��° ���ں��� ó��
		for (i = 1; i < len; i++) {
			if (S[i] != r_char) {
				if (r_cnt >= M) {
					// �ݺ��Ǵ� ������ �����Ͽ� ����Ѵ�
					print_short(r_char, r_cnt);
				}
				else {
					// �ݺ��Ǵ� ������ �״�� ����Ѵ�
					print_raw(r_char, r_cnt);
				}
				r_char = S[i];
				r_cnt = 1;
			}
			else {
				r_cnt++;
			}
		}		
	}

	public static void main(String[] args) {
		Main m = new Main();
		
		m.inputData();		//	�Է� �Լ�
		m.Solve();			//	���� Ǯ��
	}
}
