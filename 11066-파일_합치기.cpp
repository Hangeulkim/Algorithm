#include<bits/stdc++.h>

using namespace std;

int T,K,tmp;
int dp[501][501];
int psum[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>K;
        vector<int> input(K+1);
        for(int i=1;i<=K;i++){
            cin>>input[i];
            psum[i]=psum[i-1]+input[i];
        }

        for(int d=1;d<K;d++){
            for(int l=1;l+d<=K;l++){
                int r=l+d;
                dp[l][r]=987654321;
                for(int i=l;i<r;i++){
                    dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+psum[r]-psum[l-1]);
                }
            }
        }


        cout<<dp[1][K]<<'\n';
    }

    return 0;
}
