#include<bits/stdc++.h>

using namespace std;

int N,tmp,bonus;
int dp[10001];
string input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>input;
    for(int i=0;i<N;i++){
        if(input[i]=='O'){
            dp[i+1]=dp[i]+(i+1)+bonus;
            bonus++;
        }
        else{
            dp[i+1]=dp[i];
            bonus=0;
        }
    }
    cout<<dp[N]<<'\n';

    return 0;
}
