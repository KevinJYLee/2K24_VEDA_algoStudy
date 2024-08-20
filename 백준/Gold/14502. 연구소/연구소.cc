#include <iostream>
#include <vector>

using namespace std;

int N,M;

class loc{
public:
    loc(int p_x,int p_y):x(p_x),y(p_y){}
    int x;
    int y;
};

vector<loc> viruses;

bool isValidIndex(loc& boom){
    if(boom.x<0||boom.y<0||boom.x>=M||boom.y>=N) return false;
    return true;

}

//초기호출은 boom 지역에서 질병이 발생한 게 확정인 상황에서 호출되어야 한다.  보드를 재귀적으로 색칠한다.
void spread(loc& boom, vector<vector<int>>& Current){
    
    loc east(boom.x+1,boom.y);
    loc west(boom.x-1,boom.y);
    loc north(boom.x,boom.y-1);
    loc south(boom.x,boom.y+1);

    if(isValidIndex(boom)){
	if(isValidIndex(east)&&Current[east.y][east.x]==0){
	   
	    Current[east.y][east.x] = 2;

	    spread(east,Current);
	}
	        
	if(isValidIndex(west)&&Current[west.y][west.x]==0){
	    Current[west.y][west.x] = 2;

	    spread(west,Current);
	}

	
	if(isValidIndex(north)&&Current[north.y][north.x]==0) {
	    Current[north.y][north.x] = 2;
	    spread(north,Current);
	}
		
	if(isValidIndex(south)&&Current[south.y][south.x]==0) {
	    Current[south.y][south.x] = 2;
	    spread(south,Current);
	}
    }
}

//주어진 가상보드에서의 안전지대 개수 출력
//이걸근데 재귀호출을 하는게 맞나?해야지. 보드 작잖아.
int simulate(vector<vector<int>>& Current){
    
    int len(viruses.size());

    for(int i = 0;i<len;i++){
	spread(viruses[i],Current);
    }

    int ans(0);

    for(int i = 0;i<N;i++){
	for(int j = 0;j<M;j++){
	    if(Current[i][j] == 0) ans++;
	}
    }
    
    return ans;
}

int solve(vector<vector<int>>& Board,vector<loc> spaces,  const int& N, const int& M){


    int len(spaces.size());

    int ans(0);
    for(int i = 0;i<len-2;i++){
	for(int j = i+1;j<len-1;j++){
	    for(int k = j+1;k<len;k++){
		vector<vector<int>> Current(Board);

		Current[spaces[i].y][spaces[i].x] = 1;
		Current[spaces[j].y][spaces[j].x] = 1;
		Current[spaces[k].y][spaces[k].x] = 1;

		int cur = simulate(Current);
		if(cur>ans) ans = cur;
		
	    }
	}
    }
    return ans;
}

int main(){
    
    int tmp;

    cin>>tmp;

//    const int N(tmp);
    N = tmp;
    cin>>tmp;
    M = tmp;
  //  const int M(tmp);

    vector<loc> spaces;
    vector<vector<int>> Board;

    //세로 i, 가로 j
    for(int i = 0;i<N;i++){
	vector<int> tmp_vec;
	for(int j = 0;j<M;j++){
	    cin>>tmp;

	    if(tmp==0) spaces.push_back(loc(j,i)); 
	    if(tmp==2) viruses.push_back(loc(j,i));
	    tmp_vec.push_back(tmp);
	}
	Board.push_back(tmp_vec);
    }

 cout<<solve(Board,spaces,N,M);    
  
/*
    loc LC(0,0);
   spread(LC,Board);

   for(int i = 0;i<N;i++){
       for(int j = 0;j<M;j++){
	    cout<<Board[i][j]<<' ';
       }
       cout<<endl;
   }
*/


    return 0; 
}