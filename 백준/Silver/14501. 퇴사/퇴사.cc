#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Interview{

public:

    Interview(int d,int p){

	this->dur = d;
	this->profit = p;

    }


    int dur;
    int profit;


};

vector<Interview> Table;

//날짜는 0 ~ N-1 이다..
int N;

//단순비교인라인함수

inline int myMax(int a,int b){

    if(a>b) return a;
    return b;

}

//특정 날짜에 특정 프로핏을 지닌 채로 시작했을 때, 재귀와 문제분절을 통해  거둘수 있는 최대수익 리턴
int solve(int today, int profit){

    //day : Table 에서 불러와야 하는 인덱스, 
    //profit : 현재까지 누적된 액수
    
    if(today==N) return profit;

    //기저사례 처리 : 호출된 날짜자체가 범위를 벗어난 경우
    //아예 일리갈 하므로 profit = 0 이다.
    if(today>N){

	profit = 0;
        return 0;
    }

    //기저사례 처리 : 오늘이 마지막 날인 경우
    if(today==N-1){
    
	if(Table[today].dur==1) return profit+Table[today].profit;
	else return profit;
    
    }

    //기본 처리 : 내일꺼부터 다시 보던지, 아니면 오늘꺼 상담 진행한 기준으로 보던지
    return myMax(solve(today+1,profit), solve(today+Table[today].dur,profit+Table[today].profit));



}


int main(){

    cin>>N;


    for(int i = 0;i<N;i++){

	int tmp_day,tmp_profit;

	cin>>tmp_day>>tmp_profit;

	Table.push_back(Interview(tmp_day,tmp_profit));

    }

    int ans = solve(0,0);

    cout<<ans;

    return 0;
}