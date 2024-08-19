#include <iostream>
#include <vector>

using namespace std;

//동서북남..
const vector<int> dx = {1,-1,0,0};
const vector<int> dy = {0,0,-1,1};

class loc{
public:
    loc(int p_x,int p_y):x(p_x),y(p_y){};
    int x;
    int y;
};

class Dice{

public:

    Dice(int su,int sb,int s1,int s2 ,int s3 ,int s4, loc p_pos):side_up(su),side_bot(sb),side1(s1),side2(s2),side3(s3),side4(s4),pos(p_pos){
	
    }

    int side_up;
    int side_bot;
    loc pos;
    

    //동서북남이 1234 였던것 기억하는가?
    int side1;
    int side2;
    int side3;
    int side4;

    //동서북남으로 구르는 경우..
    //

    //동
    void roll1(){
	int tmp = side_up;

	side_up = side2;
	side2 = side_bot;
	side_bot = side1;
	side1 = tmp;


	pos.x = pos.x+dx[0];
	pos.y = pos.y+dy[0];
    }

    //서
    void roll2(){
	int tmp = side_up;

	side_up = side1;
	side1 = side_bot;
	side_bot = side2;
	side2 = tmp;

	pos.x = pos.x+dx[1];
	pos.y = pos.y+dy[1];
    };

    //북 
    void roll3(){
	
	int tmp = side_up;

	side_up = side4;
	side4 = side_bot;
	side_bot = side3;
	side3 = tmp;
    
	pos.x = pos.x+dx[2];
	pos.y = pos.y+dy[2];
    };

    //남
    void roll4(){
	int tmp = side_up;

	side_up = side3;
	side3 = side_bot;
	side_bot = side4;
	side4 = tmp;
    
	pos.x = pos.x + dx[3];
	pos.y = pos.y + dy[3];
    };

    void show(){

	cout<<"\n현재위치 :\n"<<pos.x<<","<<pos.y;
	cout<<"\n상하 : "<<side_up<<' '<<side_bot<<endl;
	cout<<"둥서북남 : "<<side1<<' '<<side2<<' '<<side3<<' '<<side4<<endl;
    }
};

void mySwap(int& a, int&b){
    int& tmp = a;

    a = b;
    b = tmp;
}

//굴리고 나서 접촉..
void contact(Dice& GameDice,vector<vector<int>>& Board){
    int& bottom(GameDice.side_bot);
    int& bNum(Board[GameDice.pos.y][GameDice.pos.x]);

    //이동한 칸에 쓰여있는 정수가 0이면, 주사위가 숫자를 싸고 간다.
    //이동한 칸에 쓰여있는 정수가 0이 아니면, 주사위가 숫자를 잡아먹는다.
    if(bNum==0) bNum = bottom;
    else if(bNum!=0){
	bottom = bNum;
	bNum = 0;
    }
    

}

//굴려주고 함수참조만 할거야.
//호출만 정신차리고 하시면 됩니다 ...
void solve(vector<vector<int>>& Board,Dice& GameDice, vector<int> Movements,const int& N, const int& M){
    
    for(int i = 0;i<Movements.size();i++){
	loc next(GameDice.pos.x+dx[Movements[i]-1], GameDice.pos.y+dy[Movements[i]-1]);	

	if(next.x==M||next.y==N||next.x==-1||next.y==-1);
	else{

	    //동서북남
	    if(Movements[i]==1){
		GameDice.roll1();		
	    }else if(Movements[i]==2){
		GameDice.roll2();
	    }else if(Movements[i]==3){
		GameDice.roll3();
	    }else{
		GameDice.roll4();
	    }

	    
	    contact(GameDice,Board);

        cout<<GameDice.side_up<<endl;

	}
    }
}


int main(){
    int tmp_int;
    cin>>tmp_int;    
    const int N(tmp_int);

    cin>>tmp_int;
    const int M(tmp_int);
    
    //[세로][가로]
    vector<vector<int>> Board;

    int tmp_int1;
    //세로 - 가로
    cin>>tmp_int>>tmp_int1;

    //응 xy 좌표대로 쓸거야 : (x,y) 
    loc DiceLoc(tmp_int1, tmp_int);
    
    cin>>tmp_int;
    const int K(tmp_int);


    for(int i = 0;i<N;i++){
	vector<int> tmp_vec;
	for(int j = 0;j<M;j++){
	    cin>>tmp_int;
	    tmp_vec.push_back(tmp_int);
	}
	Board.push_back(tmp_vec);
    }

    vector<int> Movements(K);
    for(int i = 0;i<K;i++) cin>>Movements[i];

// 입력페이즈 종료 ...
// 입력체크한번 갈까요?


// 주사위를 K 회 굴리는 절차 설계
    Dice GameDice(0,0,0,0,0,0,DiceLoc);
    solve(Board,GameDice,Movements,N,M);

    return 0;
}

