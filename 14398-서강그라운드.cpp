#include<bits/stdc++.h>

using namespace std;

int n,m,r,t,a,b,l;
int dist[101][101];
int dat[101];
int ret=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&dist[0][0],&dist[100][101],87654321);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>dat[i];
        dist[i][i]=0;
    }
        
    for(int i=1;i<=r;i++){
        cin>>a>>b>>l;
        dist[a][b]=l;
        dist[b][a]=l;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]>m)
                continue;
            tmp+=dat[j];
        }
        ret=max(ret,tmp);
    }
    cout<<ret<<'\n';

    return 0;
}