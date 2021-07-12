#include<bits/stdc++.h>

using namespace std;

int cnt=0;
int N,M;
char arr[501][501];

int chk[501][501];

int dfs(int y, int x){
    if(y<0||x<0||y>=N||x>=M||chk[y][x]==1)
        return 1;
    else if(chk[y][x]==0)
        return 0;

    chk[y][x]=0;
    switch (arr[y][x])
    {
        case 'U':
        chk[y][x]=dfs(y-1,x);
        break;
    
        case 'R':
        chk[y][x]=dfs(y,x+1);
        break;

        case 'D':
        chk[y][x]=dfs(y+1,x);
        break;

        case 'L':
        chk[y][x]=dfs(y,x-1);
        break;
    }

    if(chk[y][x]==1)
        cnt++;
    return chk[y][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            chk[i][j]=-1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(chk[i][j]!=-1){
                
                continue;
            }
                
            dfs(i,j);
        }
    }
    cout<<cnt<<'\n';

    return 0;
}