#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int on_bridge = 0;
    queue<pair<int, int> > q;
    
    for(int i=0;i<truck_weights.size();i++){
        answer++;
        if(answer - q.front().first - bridge_length == 0){
            on_bridge -= q.front().second;
            q.pop();
        }
        
        while(weight - on_bridge < truck_weights[i]){
            int t = q.front().first;
            int w = q.front().second;
            
            q.pop();
            
            on_bridge -= w;
            answer =  bridge_length + t;
        }
        
        q.push({answer,truck_weights[i]});
        on_bridge+=truck_weights[i];
    }
    answer = q.back().first + bridge_length;
    
    return answer;
}