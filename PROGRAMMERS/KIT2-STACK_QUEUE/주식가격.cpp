#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int> > st;
    
    int len=prices.size();
    for(int i=len-1;i>=0;i--){
        int num=len-1;
        
        while(!st.empty()){
            if(st.top().first>=prices[i]){
                st.pop();
            }
            
            else{
                num = st.top().second;
                break;
            }
        }
        
        answer.push_back(num-i);   
        st.push({prices[i],i});
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}