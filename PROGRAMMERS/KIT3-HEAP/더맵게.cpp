#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(auto it : scoville){
        pq.push(it);
    }
    
    while(!pq.empty() && pq.top() < K){
        answer++;
        
        int num=pq.top();
        pq.pop();
        
        pq.push(num+2*pq.top());
        pq.pop();
    }
    
    if(pq.empty())
        return -1;
    return answer;
}