#include<bits/stdc++.h>

using namespace std;

int N;
long long dp[31][31];

long long find(int W, int H){
    if(W==0)
        return 1;

    if(W<0||H<0)
        return 0;

    if(dp[W][H]!=-1)
        return dp[W][H];

    dp[W][H]=find(W,H-1)+find(W-1,H+1);
    return dp[W][H];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin>>N;
        if(N==0)
            break;
        memset(dp,-1,sizeof(dp));
        cout<<find(N,0)<<'\n';
    }

    return 0;
}
