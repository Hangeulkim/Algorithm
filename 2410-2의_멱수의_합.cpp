#include<iostream>

using namespace std;

long dp[1000001];
int N;

void input(){
    cin>>N;
}

void solution(){
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=N;++i){
        dp[i]=dp[i-1];
        if(i%2==0){
            dp[i]+=dp[i/2];
        }
        dp[i]%=1'000'000'000;
    }

    cout<<dp[N]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}

/*
3
1 1 1
1 2

4
1 1 1 1
1 1 2
2 2
4

5
1 1 1 1 1
1 1 1 2
1 2 2
1 4

6
1 1 1 1 1 1
1 1 1 1 2
1 1 2 2
1 1 4
2 2 2
2 4
*/