#include<iostream>

using namespace std;

int n;
int dp[1001];
int nums[1001];

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        dp[i]=1;
    }
        
}

void solution(){
    int ret=0;

    for(int now=0;now<n;now++){
        for(int prev=0;prev<now;prev++){
            if(nums[now] > nums[prev])
                dp[now]=max(dp[now],dp[prev]+1);
        }
        ret=max(ret,dp[now]);
    }

    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}