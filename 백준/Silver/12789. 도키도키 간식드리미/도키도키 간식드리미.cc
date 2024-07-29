#include <iostream>
#include <deque>

using namespace std;

/*
 필요한 메소드를 정의하고 덱과 리스트 중 선택한다. 배열 vs 연결리스트 
 
 - 만약, 현재 통과 차례가 아닌 사람이 줄에 서있다면, 따로 선언된 후입선출 스택에 들어간다. 이 스택을 subline 이라 하자. 원본 줄은 mainline.

 - 마찬가지로 진행되다가, 현재 통과 차례인 사람을 찾으면 그 사람은 원본 줄에서 pop 된다.

 - 이렇게 한다고 순서대로의 입력이 보장되지 않는다. - subline 서열은 반드시 앞 사람이 위에 존재해야 하기 때문이다

- 그냥 스택으로만 2개 존재해도 되는듯함 : top 만 검사 및 사용할 거니까..


줄 알고리즘..

if (메인 톱) == cur => 무조건 main 에서 팝 및 cur 증가시키고 다음 흐름으로

일단 main 에서 팝하고 그대로 sub 에 push 를 하는데, 
만약 순서가 거꾸로면 터진다. => 그러므로,

else if(sub.empty()) 일단 push
else(디폴트 상태) sub.top 과 main.top 비교 후 터트릴지 sub 에 push 할지 결정



...기저사례

main 이 비었으면, cur = N+1 하고 그대로 종료시켜도 좋음.
ㄴ> sub 가 invalid 한 사례는 아예 용납을 안하는 알고리즘이기 때문


+main 에서 무언가가 pop 되면서, sub.top 이 cur 이 되었다면 ?
 */

deque<int> mainline;
deque<int> subline;


int main(){

    int N;
    int tmp;

    int cur(1);

    cin>>N;

    for(int i = 0;i<N;i++){
	cin>>tmp;
	mainline.push_back(tmp);
    }

    while(1){
	if(mainline.empty()){
	    cur = N+1;



	    break;
	}
	if(mainline.front()==cur){
	    mainline.pop_front();

	    cur++;
	}
	else{
	    if(subline.empty()){
	       	subline.push_back(mainline.front());
		mainline.pop_front();
	    }
	    else if(subline.back()==cur){
		subline.pop_back();
		cur++;
	    }
	    else if(subline.back()<mainline.front()){

		break;
	    }
	    else{
		subline.push_back(mainline.front());
		mainline.pop_front();
	    }
	}
    }

    if(cur==N+1){

	cout<<"Nice";
    }
    else cout<<"Sad";


    return 0;
}
