#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cnt = 1, num = 0;
    priority_queue<pair<int, int> ,vector<pair<int,int> >, greater<pair<int, int> > > pq;
    
    sort(jobs.begin(),jobs.end());
    
    pq.push({jobs[0][1],jobs[0][0]});
    num = jobs[0][0];
    while(!pq.empty()){
        num+=pq.top().first;
        answer+=num-pq.top().second;
        
        pq.pop();
        while(cnt<jobs.size() && jobs[cnt][0]<=num){
            pq.push({jobs[cnt][1],jobs[cnt][0]});
            cnt++;
        }
        
        if(cnt<jobs.size() && pq.empty()){
            pq.push({jobs[cnt][1],jobs[cnt][0]});
            num=jobs[cnt++][0];
            while(cnt<jobs.size() && jobs[cnt][0]<=num){
                pq.push({jobs[cnt][1],jobs[cnt][0]});
                cnt++;
            }
        }
    }
    
    answer/=jobs.size();
    return answer;
}