#include<bits/stdc++.h>

using namespace std;

int N,S,M,tmp;
int input[101];
bool dp[101][1001]={false,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>S>>M;
    dp[0][S]=true;
    for(int i=1;i<=N;i++){
        cin>>input[i];

        for(int j=0;j<=M;j++){
            if(!dp[i-1][j])
                continue;
            if(j+input[i]<=M){
                dp[i][j+input[i]]=true;
            }
            if(j-input[i]>=0){
                dp[i][j-input[i]]=true;
            }
        }
    }

    for(int i=M;i>=0;i--){
        if(dp[N][i]){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;

    return 0;
}
