#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> li;
    for(auto it : clothes){
        if(li.find(it[1])==li.end())
            li[it[1]]=0;
        li[it[1]]++;
    }
    
    int answer=0;
    
    for(auto it : li){
        answer=answer+answer*it.second+it.second;
    }
    
    return answer;
}