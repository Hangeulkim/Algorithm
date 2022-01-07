#include<bits/stdc++.h>

using namespace std;
int n,m,r,t;
int a,b,l;

vector<pair<int, int> > loc[101];
int item[101];
int dist[101][101];
int ret=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&dist[0][0],&dist[100][101],87654321);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>item[i];
        dist[i][i]=0;
    }
        
    for(int i=1;i<=r;i++){
        cin>>a>>b>>l;
        loc[a].push_back({b,l});
        loc[b].push_back({a,l});
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){

            }
        }
    }

    
    cout<<ret<<'\n';

    return 0;
}