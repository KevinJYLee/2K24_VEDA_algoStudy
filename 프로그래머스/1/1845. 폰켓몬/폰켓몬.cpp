#include <vector>
using namespace std;

//폰켓몬 문제 ...
/*
N 마리중 N/2 마리를 가져도 좋다.

1. 종류에 따라 번호를 부여받는 폰켓몬들
2. 최대한 다양한 종류의 폰켓몬을 가지고 싶다.

입출력
- 폰켓몬 번호 리스트, 크기 N 의 int 배열이 주어진다.
- 이중 N/2 마리를 찾아서 얻을 것인데, You should seek for the maximum diversity.

- return the maximum diversity.
- this is a key-value hashmap problem.

solution
- 
*/

#include <unordered_map>

//find(n) function checks if there is a key..
unordered_map<int, int> pukimun;
int count(0);

inline void check_and_add(const int& i){
    if(pukimun.find(i)==pukimun.end()){
        pukimun[i] = 0;
        count++;
    }
}

int solution(vector<int> nums)
{
    int answer = 0;
    int len = nums.size();
    for(const auto& i : nums){
        check_and_add(i);
    }
    if(len/2>count) return count;
    else return len/2;
    
}