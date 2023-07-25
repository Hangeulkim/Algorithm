#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int> > coins;
bool dp[100001];
int N;
int sum;

void input(){
    cin>>N;

    coins.resize(N);
    for(int i=0;i<N;++i){
        cin>>coins[i].first>>coins[i].second;
        sum += coins[i].first * coins[i].second;

        for(int i=1;i<=coins[i].second;++i)
            dp[i*coins[i].first] = true;
    }
}

void solution(){
    dp[0] = true;

    if(sum % 2 == 1){
        cout<<0<<'\n';
        return ;
    }

    for(int i=0;i<coins.size();++i){
        int value = coins[i].first;
        int nums = coins[i].second;

        for(int j=sum/2;j>=value;--j){
            if(dp[j-value]){
                for(int k=0;k<nums;++k){
                    if(j + value * k <= sum/2)
                        dp[j + value * k ] = true;
                    else 
                        break;
                }
            }
        }
    }

    cout<<dp[sum/2]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 3;
    while(T--){
        sum = 0;
        coins.clear();
        fill(&dp[0], &dp[100001], false);
        input();
        solution();
    }

    return 0;
}