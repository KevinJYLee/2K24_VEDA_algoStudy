#include <string>
#include <vector>

using namespace std;
/*
give a number of fasion compositions.

1. each cloth has <name,area>
2. coney can choose NOT to wear certain kind of area.

3. the number of cloth is 30..

clothes[i][0] : name
clothes[i][1] : area


*/

#include <unordered_map>
unordered_map <string,int> closet;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    //record number of clothes in each area.
    for(const auto& it : clothes){
        if(closet.find(it[1])==closet.end()) closet[it[1]] = 1;
        else closet[it[1]]++;
    }
    
    //calculation : multiply each (number of clothes + 1) to count wearing non.
    //just do a correct -1 to get rid of going out naked.
    answer = 1;
    for(const auto& kv_item : closet){
        answer*=(kv_item.second+1);
    }
    answer--;

    
    return answer;
}