#include<bits/stdc++.h>

using namespace std;

int N;
int jong[2999][2999];

int m,z,p;

void dfs(int sy,int sx, int ey, int ex, int sz){
    bool bf=false;
    for(int i=sy;i<=ey;i++){
        for(int j=sx;j<=ex;j++){
            if(jong[i][j]!=jong[sy][sx]){
                bf=true;
                break;
            }
        }
        if(bf)
            break;
    }

    if(bf){
        for(int i=sy;i<=ey;i+=sz/3){
            for(int j=sx;j<=ex;j+=sz/3){
                dfs(i,j,i+sz/3-1,j+sz/3-1,sz/3);
            }
        }
    }
    else{
        switch (jong[sy][sx])
        {
        case -1:
            m++;
            break;
        
        case 0:
            z++;
            break;
        
        case 1:
            p++;
            break;
        }        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>jong[i][j];
        }
    }
    dfs(1,1,N,N,N);
    cout<<m<<'\n'<<z<<'\n'<<p<<'\n';


    return 0;
}