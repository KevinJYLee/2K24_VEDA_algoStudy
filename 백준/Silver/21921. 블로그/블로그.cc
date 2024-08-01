#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    vector<int> Visitors;
    vector<int> Sums;

    int N,X;
    cin>>N>>X;
    int tmp;


    //우선 N 개 받고 시작
    for(int i = 0;i<N;i++){
    
	cin>>tmp;
	Visitors.push_back(tmp);
    }

    int sum(0);
   
    //초기 방문자값 기록
    for(int i = 0;i<X;i++){
	sum+=Visitors[i];
    }
    Sums.push_back(sum);

    //
    for(int i = 0;i<=N-X;i++){
	sum-=Visitors[i];
	sum+=Visitors[i+X];
	Sums.push_back(sum);
    }

    sort(Sums.begin(),Sums.end());

    int count(0);
    int flag(1);
    int idx = Sums.size()-1;

    int cur = Sums[idx];
    if(cur==0){
	
	cout<<"SAD";
    }
    else{
        while(flag){
	    count++;
	    idx--;
	    if(idx<0||Sums[idx]!=cur) flag = 0;

        }	

	cout<<cur<<'\n'<<count;
    }

    return 0;
}

