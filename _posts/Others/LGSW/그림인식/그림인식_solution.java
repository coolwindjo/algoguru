import java.util.Scanner;

public class Main {
	int N;//도화지 크기
	char A[][] = new char[10 + 2][10 + 2];//도화지 색정보
	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) A[i] = sc.next().toCharArray();
		sc.close();
	}
	
	int Solve(){
		int i, r, c, minr, minc, maxr, maxc, cnt = 0;
		int check[] = new int[10];
		for (i = '1'; i <= '9'; i++){
			//i번색 상하좌우 찾기
			minr = minc = 10;
			maxr = maxc = 0;
			for (r = 0; r < N; r++){
				for (c = 0; c < N; c++){
					if (A[r][c] != i) continue;
					if (minr > r) minr = r;
					if (maxr < r) maxr = r;
					if (minc > c) minc = c;
					if (maxc < c) maxc = c;
				}
			}
			if (minr == 10) continue;//해당 색 없음
			//i번색 영역에 칠해진 다른 색 찾아 표시하기
			check[i-'0']++;//해당색 표시
			for (r = minr; r <= maxr; r++){
				for (c = minc; c <= maxc; c++){
					if (A[r][c] == i) continue;//i번 색이면 skip
					check[A[r][c]-'0']++;//해당색에 덮여진 다른색 표시하기
				}
			}
		}
		//check 배열에 1로 카운트 된 색이 다른색을 덧칠하지 않은 색임(0이면 없는 색임)
		for (i = 1; i <= 9; i++){
			if (check[i] == 1) cnt++;
		}
		return cnt;
	}

	public static void main(String[] args){
		int ans = -1;
		Main m = new Main();

		m.InputData();				//	입력 함수

		ans = m.Solve();//	코드를 작성하세요

		System.out.println(ans);//출력
	}
}