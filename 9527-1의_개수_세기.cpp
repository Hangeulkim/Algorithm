#include<iostream>

using namespace std;

long long A,B;
long long dp[55];

void input(){
    cin>>A>>B;
}

long long calc(long long num){
    long long sum = num & 1;

    for(int i = 54 ; i > 0 ; --i){
        if(num & (1LL << i)){
            num -= 1LL << i;
            sum += dp[i-1] + num + 1; 
        }
    }
    return sum;
}



void solution(){
    dp[0] = 1;
    for(int i = 1; i< 55 ; ++i){
        dp[i] = dp[i-1] * 2 + (1LL << i);
    }

    long long ans = calc(B) - calc(A-1);
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}