#include<bits/stdc++.h>

using namespace std;

int n,m;
int dist[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a,b,c;
    fill(&dist[0][0],&dist[100][101],87654321);
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==87654321)
                cout<<0<<" ";
            else 
                cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}