#include <string>
#include <vector>

using namespace std;

//1. add the whole phone book to the map
//2. iterate through the whole book with find(string)

#include <unordered_map>
unordered_map<string,int> numbers;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(const auto& i : phone_book){
        numbers[i] = 0;
    }
    
    for(const auto& number : phone_book){
        for (size_t i = 1; i < number.length(); i++) {
            if (numbers.find(number.substr(0, i)) != numbers.end()) {
                return false;  // 접두어가 존재하는 경우
            }
        }
    }
    
    return true;
}