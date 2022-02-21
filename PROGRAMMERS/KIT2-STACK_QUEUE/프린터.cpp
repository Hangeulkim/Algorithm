#include <string>
#include <vector>
#include<queue>

using namespace std;

queue<pair<int, int> > q;
int num[10];
int highp;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i=0;i<priorities.size();i++){
        q.push({i,priorities[i]});
        num[priorities[i]]++;
        highp=max(highp,priorities[i]);
    }
    
    while(!q.empty()){
        int loc = q.front().first;
        int pri = q.front().second;
        
        
        q.pop();
        if(pri == highp){
            answer++;
            if(loc == location)
                break;
            num[pri]--;
            if(!num[pri]){
                for(int i=9;i>=0;i--){
                    if(num[i]){
                        highp=i;
                        break;
                    }
                }
            }
        }
        else
            q.push({loc,pri});
    }
    
    return answer;
}