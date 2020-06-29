#include<bits/stdc++.h>

using namespace std;

int N;
int dp[1001];
int input[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>input[i];
        dp[i]=987654321;
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],input[j]+dp[i-j]);
        }
    }
    cout<<dp[N];


    return 0;
}
