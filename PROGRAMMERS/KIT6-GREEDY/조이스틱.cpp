#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool chk[35];
int n;
int answer=987'654'321;

bool vst(){
    for(int i=0;i<n;i++)
        if(!chk[i])
            return true;
    return false;
}

void dfs(int ptr, int cnt, string name){
    if(!vst()){
        answer=min(cnt,answer);
        return;
    }

    int d=0,u=0,tmp;
    for(int i=1;i<=n/2;i++){
        tmp=(ptr+i)%n;
        if(!chk[tmp]){
            u=i;
            break;
        }
    }
    if(u>0){
        chk[tmp]=true;
        dfs(tmp,cnt+min('Z'-name[tmp]+1,name[tmp]-'A')+u,name);
        chk[tmp]=false;
    }
    

    for(int i=1;i<=n/2;i++){
        tmp = ptr-i;
        if(tmp<0)
            tmp+=n;
        if(!chk[tmp]){
            d=i;
            break;
        }
    }
    
    if(d>0){
        chk[tmp]=true;
        dfs(tmp,cnt+min('Z'-name[tmp]+1,name[tmp]-'A')+d,name);
        chk[tmp]=false;
    }
}

int solution(string name) {
    n = name.length();
    
    for(int i=0;i<n;i++)
        if(name[i]=='A')
            chk[i]=true;    
    
    chk[0]=true;
    dfs(0,min('Z'-name[0]+1,name[0]-'A'),name);
    
    return answer;
}