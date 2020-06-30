#include<bits/stdc++.h>

using namespace std;

int length;
int N;
int input[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int maxn=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>input[i];
        dp[i]=0;
        for(int j=1;j<i;j++){
            if(input[i]>input[j]&&dp[i]<dp[j]){
                dp[i]=dp[j];
            }
        }
        dp[i]+=input[i];
        maxn=max(maxn,dp[i]);
    }
    cout<<maxn<<'\n';

    return 0;
}
