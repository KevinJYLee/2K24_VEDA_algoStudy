#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> real;

int main(void){

    int N;
    
    cin>>N;

    int tmp;

    for(int i = 0;i<N;i++){
    
	cin>>tmp;

	real.push_back(tmp);

    }

    int len = real.size();
    sort(real.begin(),real.end());
    
    int min_d = real[0];
    int max_d = real[len-1];
    
    cout<<min_d * max_d;

    return 0;
}
