#include<bits/stdc++.h>

using namespace std;

int N,M;
int result=0;
char input[10][10];
bool gs[10][10];

int find(){
    int ret=0,tmp=0,y,x;
    for(y=1;y<=N;y++){
        for(x=1,tmp=0;x<=M;x++,tmp*=10){
            if(!gs[y][x]){
                tmp+=(input[y][x]-'0');
            }
            else{
                ret+=tmp/10;
                tmp=0;
            }
        }
        ret+=tmp/10;
    }


    for(x=1;x<=M;x++){
        for(y=1,tmp=0;y<=N;y++,tmp*=10){
            if(gs[y][x]){
                tmp+=(input[y][x]-'0');
            }
            else{
                ret+=tmp/10;
                tmp=0;
            }
        }
        ret+=tmp/10;
    }

    return ret;
}

void dfs(int y, int x){
    if(y==N+1&&x==M+1){
        result=max(result,find());
        return ;
    }

    if(x==M+1){
        dfs(y+1,0);
        return;
    }

    gs[y][x]=true;
    dfs(y,x+1);
    gs[y][x]=false;
    dfs(y,x+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            gs[i][j]=false;
            cin>>input[i][j];
        }
    }

    dfs(1,1);

    cout<<result<<'\n';

    return 0;
}
