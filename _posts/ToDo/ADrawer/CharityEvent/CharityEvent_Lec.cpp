#include <iostream>
using namespace std;
int N;//보내려는 물품 개수
int C[10];//BOX 개수(1,  5,  10,  50,  100,  500,  1000,  3000,  6000,  12000 순)
int sol[10];//보내는 BOX 개수
int num[] = {1,  5,  10,  50,  100,  500,  1000,  3000,  6000,  12000};
int Solve(){//남기는 BOX수를 최소로 하기(그러면 많은 박스를 보내게됨)
    int sum=0,  totalcnt=0;
    //1.재고량 파악하기
    for (int i=0; i<10; i++){
        sum += num[i] * C[i];
    }
    sum -= N;//총 제고량 - 보내는 물품수 = 남는 물품수
    //2.남는 물품수를 최소 BOX로 남기기
    for (int i=9; i>=0; i--){//큰 BOX부터
        int cnt = sum / num[i];
        if (cnt > C[i]) cnt = C[i];//창고에 있는 박스수 보다 많으면 그 개수 만큼 남길수있음
        sum -= cnt * num[i];//i번 박스로 남기는 물품수 빼기
        sol[i] = C[i] - cnt;//재고 BOX수 - 남기는 BOX수 = 보낼 BOX수
        totalcnt += sol[i];//보내는 BOX 총개수
    }
    return totalcnt;
}
void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}
void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}
int main(){
	int ans = -1;
	InputData();//	입력 함수
	ans = Solve();//	코드를 작성하세요
	OutputData(ans);//	출력 함수
	return 0;
}