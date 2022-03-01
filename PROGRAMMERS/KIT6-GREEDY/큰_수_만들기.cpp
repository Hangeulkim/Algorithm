#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    
    for(int i=0;i<number.length();i++){
        while(!s.empty()&&k&&s.top()<number[i]){
            s.pop();
            k--;
        }
        s.push(number[i]);
    }
    
    while(!s.empty()&&k){
        s.pop();
        k--;
    }
    
    while(!s.empty()){
        answer+=s.top();
        s.pop();
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}