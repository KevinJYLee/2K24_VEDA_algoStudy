#include <iostream>
#include <vector>

using namespace std;

//북동남서
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

int N,M;

class loc{

public:
    loc(int p_x,int p_y):x(p_x), y(p_y){
    }

    int x,y;

};

bool isValidIndex(loc& pos){

    if(pos.x<0||pos.y<0||pos.x>=M||pos.y>=N) return false;
    return true;
}

class Cleaner{

public:
    Cleaner(int p_x,int p_y,int p_dir):pos(loc(p_x,p_y)),dir(p_dir){
    }

    loc pos;
    int dir;

    //반시계방향으로 회전한다.
    void turn(){
	dir = (dir+3)%4;
    }
    void front(){
	pos.x = pos.x+dx[dir];
	pos.y = pos.y+dy[dir];

    }
    void back(){
	pos.x = pos.x-dx[dir];
	pos.y = pos.y-dy[dir];

    }

    void show(){
	cout<<"\n현재 포지션:\n("<<pos.x<<','<<pos.y<<")\n";
	cout<<"현재 방향 : "<<dir<<endl;

    }

};



//무한반복문으로 돌려볼까..
//
int counter(0);
int solve(vector<vector<int>>& Board, Cleaner& Robot){
    
    int ans(0);

    while(1){

	if(Board[Robot.pos.y][Robot.pos.x]==0){
	    //벽과 구분하기 위해 2로 만듭니다.
	    Board[Robot.pos.y][Robot.pos.x] = 2;
	    ans++;
	}
	
	//이 전체 코드블럭에 오류가 있을 수 있는데, 바로 벽을 마주하는 경우이다.
	//그런데, 이 문제는 경계면 체크가 필요 없는게 벽으로 사이드를 한번 감싸 준다.
	//
	//원래는 4방향 체크 과정에서 벽체크를 해야 해..
	//
	//4방향 모두 체크해서, 하나라도 있는지 아닌지 체크를 해야 한다.
	if(Board[Robot.pos.y-1][Robot.pos.x]==0||Board[Robot.pos.y][Robot.pos.x+1]==0||Board[Robot.pos.y+1][Robot.pos.x]==0||Board[Robot.pos.y][Robot.pos.x-1]==0){
	
	    //90도 회전 1회차
	    Robot.turn();
	    //로봇 기준의 앞방향은, 현재 로봇의 위치 + 로봇의 dir 이다.
	    //
	    //
	    //앞에 오염이 있으면 => 전진 후 다음 반복으로
	    if(Board[Robot.pos.y+dy[Robot.dir]][Robot.pos.x+dx[Robot.dir]]==0) Robot.front();
	    //앞에 오염이 없으면 => 90도 회전 2회차 
	    else{
		Robot.turn();

		//앞에 오염이 있으면
		if(Board[Robot.pos.y+dy[Robot.dir]][Robot.pos.x+dx[Robot.dir]]==0) Robot.front();
		//90도 회전 3회차
		else{
		    Robot.turn();

		    //앞에 오염이 있으면
		    if(Board[Robot.pos.y+dy[Robot.dir]][Robot.pos.x+dx[Robot.dir]]==0) Robot.front();
		    //90도 회전 4회차
		    else{
			    Robot.turn();
			    //4방향 중 1방향에는 오염이 있는 상황에서, 4회차 회전까지 왔으면 무조건 로봇은 전진한다.
			    //근데 일단은..네..
			    if(Board[Robot.pos.y+dy[Robot.dir]][Robot.pos.x+dx[Robot.dir]]==0) Robot.front();
			}
		    }
	    }
	
	//하나도 오염구역이 없는 경우
	}else{
	    if(Board[Robot.pos.y-dy[Robot.dir]][Robot.pos.x-dx[Robot.dir]]==1) break;
	    else Robot.back();
	}
    }

    return ans;
}



int main(){

    int tmp;
    int num;
    int d;

    cin>>tmp;
   // const int N(tmp);
    N = tmp;

    cin>>tmp;
    M = tmp;
//    const int M(tmp);

    //세로 - 가로 - 방향
    cin>>tmp>>num>>d;

    Cleaner Robot(num,tmp,d);
    
    vector<vector<int>> Board;
    for(int i = 0;i<N;i++){
	vector<int> tmp_vec;
	for(int j = 0;j<M;j++){

	    cin>>tmp;
	    tmp_vec.push_back(tmp);
	}
	Board.push_back(tmp_vec);

    }




    cout<<solve(Board, Robot);

    return 0;
}
