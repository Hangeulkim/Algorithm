#include<bits/stdc++.h>

using namespace std;

string input;
bool p[2501][2501];
int dp[2501];
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;

    N=input.size();
    for(int i=0;i<N;i++)    p[i][i]=true;
    for(int i=0;i<N-1;i++)  if(input[i]==input[i+1]) p[i][i+1]=true;
    for(int l=2;l<N;l++){
        for(int i=0;i+l<N;i++){
            if(input[i]==input[i+l]&&p[i+1][i+l-1])
                p[i][i+l]=true;
        }
    }

    dp[0]=1;
    for(int i=1;i<N;i++){
        if(p[0][i]) dp[i]=1;
        else{
            dp[i]=dp[i-1]+1;
            for(int j=1;j<i;j++)    
                if(p[j][i]) dp[i]=min(dp[i],dp[j-1]+1);
        }
    }
    cout<<dp[N-1]<<'\n';

    return 0;
}