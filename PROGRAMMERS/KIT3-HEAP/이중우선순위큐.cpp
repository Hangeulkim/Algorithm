#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int> > pq_min;
    map<int, int> m;
    
    for(auto it : operations){
        int num = stoi(&it[1]);
        if(it[0]=='I'){
            pq_max.push(num);
            pq_min.push(num);
            if(m.find(num)==m.end())
                m[num]=0;
            m[num]++;
        }
        else{
            if(pq_min.empty())
                continue;
            if(num==1){
                m[pq_max.top()]--;
            }
            else{
                m[pq_min.top()]--;
            }
            while(!pq_min.empty()&&!m[pq_min.top()])
                pq_min.pop();
            while(!pq_max.empty()&&!m[pq_max.top()])
                pq_max.pop();
        }
        
    }
    
    if(pq_min.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }
    
    return answer;
}