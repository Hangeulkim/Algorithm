#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sosu[10000001];
bool num[7];
string tmp;
int len;
int answer;

void dfs(string s, int cnt){
    if(cnt==len){
        if(!s.empty()&&!sosu[stoi(s)]){
            answer++;
            sosu[stoi(s)]=true;
        }
            
        return;
    }
    
    for(int i=0;i<len;i++){
        if(num[i])
            continue;
        num[i]=true; 
        dfs(s+tmp[i],cnt+1);
        num[i]=false;
        dfs(s,cnt+1);
    }
}

int solution(string numbers) {
    tmp=numbers;
    len=tmp.length();
    
    sosu[0]=true;
    sosu[1]=true;
    for(int i=2;i<sqrt(10000001);i++){
        if(sosu[i])
            continue;
        for(int j=2;i*j<10000001;j++)
            sosu[i*j]=true;
    }
    
    
    dfs("", 0);
        
    return answer;
}