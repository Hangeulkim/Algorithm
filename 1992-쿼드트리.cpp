#include<bits/stdc++.h>

using namespace std;

int N;
char arr[65][65];

void dfs(int sy, int ey, int sx, int ex, int sz){
    bool bf=false;
    for(int i=sy;i<=ey;i++){
        for(int j=sx;j<=ex;j++){
            if(arr[sy][sx]!=arr[i][j]){
                bf=true;
                break;
            }
        }
        if(bf)
            break;
    }

    if(bf){
        cout<<'(';
        for(int i=sy;i<=ey;i+=sz/2){
            for(int j=sx;j<=ex;j+=sz/2){
                dfs(i,i+sz/2-1,j,j+sz/2-1,sz/2);
            }
        }
        cout<<')';
    }
    else
        cout<<arr[sy][sx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }
    dfs(1,N,1,N,N);

    return 0;
}