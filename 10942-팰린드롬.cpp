#include<bits/stdc++.h>

using namespace std;

int N,M,tmp,S,E;
bool dp[2001][2001];
int input[2001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    memset(dp,false,sizeof(dp));
    for(int i=1;i<=N;i++){
        cin>>input[i];
        dp[i][i]=true;
        dp[i-1][i]=input[i-1]==input[i]?true:false;
        for(int j=i-2;j>=1;j--){
                if(dp[j+1][i-1]&&input[j]==input[i])
                    dp[j][i]=true;
        }
    }
    cin>>M;
    while(M--){
        cin>>S>>E;
        if(dp[S][E])
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }


    return 0;
}
