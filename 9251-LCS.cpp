#include<bits/stdc++.h>

using namespace std;

string a,b;
int dp[1001][1001];

int find(){
    int lengA,lengB;
    lengA=a.length();
    lengB=b.length();

    for(int i=0;i<lengA;i++){
        for(int j=0;j<lengB;j++){
            if(a[i]==b[j])
                dp[i+1][j+1]=1+dp[i][j];
            else
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }

    return dp[lengA][lengB];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,0,sizeof(dp));
    cin>>a>>b;
    cout<<find();

    return 0;
}
