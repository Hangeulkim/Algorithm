#include<bits/stdc++.h>

using namespace std;

int n,k,tmp;
vector<int> input;
int dp[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end());
    input.erase(unique(input.begin(),input.end()),input.end());

    int sz=input.size();
    for(int i=1;i<=k;i++){
        dp[i]=987654321;
        for(int j=0;j<sz;j++){
            if(i<input[j])
                break;
            dp[i]=min(dp[i],dp[i-input[j]]+1);
        }
    }
    if(dp[k]==987654321)
        cout<<-1;
    else
        cout<<dp[k];

    return 0;
}
