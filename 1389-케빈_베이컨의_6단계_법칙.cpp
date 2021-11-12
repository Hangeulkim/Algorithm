#include<bits/stdc++.h>

using namespace std;

int N, M;
int a,b;

int kevin[101][101];
int result[101];
int ret=-1;
void floid(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(j!=k&&i!=k&&i!=j){
                    kevin[j][k]=min(kevin[j][k],kevin[j][i]+kevin[i][k]);
                    kevin[k][j]=kevin[j][k];
                }
            }
        }
    }

    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            result[i]+=kevin[i][j];
            result[j]+=kevin[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&kevin[0][0],&kevin[100][101],987654321);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        kevin[a][b]=1;
        kevin[b][a]=1;
    }

    floid();
    ret=1;
    for(int i=2;i<=N;i++){
        if(result[i]<result[ret])
            ret=i;
    }
    cout<<ret;

    return 0;
}