#include <string>
#include <vector>

using namespace std;

/*
participants : names
completion : names who completed

ans : there is a one who didn't finish. find the name and return.
*/

#include <unordered_map>
unordered_map<string, int> names;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(const auto& it : completion){
        if(names.find(it)==names.end()) names[it] = 1;
        else names[it]++;
    }
    
    for(const auto& it : participant){
        if(names.find(it)==names.end()) return it;
        else{
            names[it]--;
            if(names[it]==0) names.erase(it);
        }
    }
    
    return answer;
}