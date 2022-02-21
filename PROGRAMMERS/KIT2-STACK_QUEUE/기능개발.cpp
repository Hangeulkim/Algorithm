#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<int, int> > q;
vector<int> answer;

void run(){
    for(int i=0;i<q.size();i++){
        int now=q.front().first;
        int spd=q.front().second;
        
        q.pop();
        
        q.push({now+spd,spd});
    }
}

void baepo(){
    int cnt=0;
    
    while(!q.empty()){
        int now=q.front().first;
        
        if(now>=100){
            cnt++;
            q.pop();
        }
        else
            break;
    }
    
    if(cnt)
       answer.push_back(cnt); 
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    for(int i=0;i<speeds.size();i++)
        q.push({progresses[i],speeds[i]});
    
    while(!q.empty()){
        run();
        baepo();
    }
    
    return answer;
}