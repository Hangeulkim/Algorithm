#include<bits/stdc++.h>

using namespace std;
vector<int> dp;
int input=0,N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>input;

        if(i>0){
            if(dp[i-1]<0){
                dp.push_back(input);
            }
            else{
                dp.push_back(dp[i-1]+input);
            }
        }
        else{
            dp.push_back(input);
        }

    }

    sort(dp.begin(),dp.end(),greater<int>());
    cout<<dp[0]<<'\n';

    return 0;
}
