#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int N;
vector<int> weight;
bool dp[31][15001];

void input(){
    cin>>N;

    weight.resize(N);
    for(int i=0;i<N;++i){
        cin>>weight[i];
    }
}

void calc(int idx, int sum){
    if(idx > N || dp[idx][sum]) return;
    dp[idx][sum]=true;

    calc(idx+1, sum + weight[idx]);
    calc(idx+1, abs(sum-weight[idx]));
    calc(idx+1, sum);
}

void solution(){
    int t, chk;
    cin>>t;

    calc(0,0);
    while(t--){
        cin>>chk;

        if(chk <= 15000 && dp[N][chk])
            cout<<"Y ";
        else
            cout<<"N ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}