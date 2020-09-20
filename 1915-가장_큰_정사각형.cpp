#include<bits/stdc++.h>

using namespace std;

int N,M;
int dp[1010][1010];
int result=0;

int main(){
    memset(dp,0,sizeof(dp));
    scanf("%d %d",&N,&M);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d",&dp[i][j]);
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(dp[i][j]){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                result=max(dp[i][j],result);
            }
        }
    }
    printf("%d\n",result*result);


    return 0;
}
