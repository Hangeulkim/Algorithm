#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ch[32];
vector<pair<int,int> > v; 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(auto it : lost)
        ch[it]--;
    for(auto it : reserve)
        ch[it]++;
    
    for(int i=1;i<=n;i++){
        if(ch[i]>=0)
            answer++;
        if(ch[i]==-1){
            if(ch[i-1]>0){
                answer++;
                ch[i-1]--;
                continue;
            }
            if(ch[i+1]>0){
                answer++;
                ch[i+1]--;
                continue;
            }
        }
    }
    
    return answer;
}