#include <string>
#include <vector>
#include <stack>

using namespace std;

int calc(vector<int> order){
    int ans=0;
    int idx=1;
    stack<int> s;
    
    int N=order.size();
    for(int i=0;i<N;++i){
        int num=order[i];
        
        //못꺼내는 경우 = 보조컨테이너에서 꺼낼수 없는 놈 or 컨테이너 맨 앞에 있는 경우
        if(idx>num&&s.top()!=num){
            break;
        }
        
        while(idx<=num){
            //1번~num이전꺼 까지 보조 컨테이너에 넣음
            s.push(idx++);
        }
        
        if(s.top()==num)
            s.pop();
        
        ++ans;
    }
    
    return ans;
}

int solution(vector<int> order) {
    int answer = 0;
    
    answer=calc(order);
    
    return answer;
}