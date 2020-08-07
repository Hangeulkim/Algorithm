#include<bits/stdc++.h>

using namespace std;

int N,M,H;
int sy,sx;
int result=987654321;

bool input[301][301];
bool fflag=false;

bool chk(){
    for(int x=1;x<=M;x++){
        int n=x;
        for(int y=1;y<=N;y++){
            if(input[y][n]){
                n++;
            }
            else if(input[y][n-1]){
                n--;
            }
        }
        if(n!=x)
            return false;
    }
    return true;
}

void dfs(int y, int x, int cnt){
    if(chk()){
        fflag=true;
        result=min(result,cnt);
        return;
    }
    if(cnt>=3||y>N){
        return ;
    }

    if(x>=M){
        dfs(y+1,1,cnt);
        return;
    }
    if(!input[y][x-1]&&!input[y][x+1]&&!input[y][x]){
        input[y][x]=true;
        dfs(y,x+1,cnt+1);
        input[y][x]=false;
    }
    dfs(y,x+1,cnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>H>>N;
    memset(input,false,sizeof(input));

    while(H--){
        cin>>sy>>sx;
        input[sy][sx]=true;
    }

    dfs(1,1,0);
    if(!fflag)
        cout<<-1<<'\n';
    else
        cout<<result<<'\n';


    return 0;
}
