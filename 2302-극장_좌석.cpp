#include<iostream>

using namespace std;

int N;
bool vip[42];
int dp[41];

void input(){
    cin>>N;

    int vcnt, tmp;
    cin>>vcnt;

    for(int i=0;i<vcnt;++i){
        cin>>tmp;
        vip[tmp] = true;
    }
}

void solution(){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=N;++i){
        //다음 사람과 바꾸는 것은 i가 1증가한 뒤에 고려해도 되므로 뒤로 넘긴다.
        if(vip[i] || vip[i-1])
            dp[i] = dp[i-1];
        else
            dp[i] = dp[i-1] + dp[i-2];
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