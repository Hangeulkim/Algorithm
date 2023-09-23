#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[4001][4001];
string a,b;

void input(){
    cin>>a>>b;
}

void solution(){
    int la = a.length(), lb = b.length();

    int ret=0;
    for(int i=0;i<la;++i){
        for(int j=0;j<lb;++j){

            if(a[i] != b[j])
                continue;
            
            if(i==0 || j==0)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j-1]+1;

            ret = max(ret, dp[i][j]);
        }
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