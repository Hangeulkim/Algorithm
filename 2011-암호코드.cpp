#include<iostream>
#include<string>

using namespace std;

string str;
int len;
int dp[5001][2];
int mod = 1'000'000;

void init(){
    fill(&dp[0][0],&dp[5000][2],0);
}

void input(){
    cin>>str;
    len=str.length();
}


void solution(){
    if(str[0]=='0'){
        cout<<0<<'\n';
        return ;
    }
    dp[0][0]=1;
    dp[1][0]=1;
    for(int i=2;i<=len;++i){
        if(str[i-1]=='0'){
            if(str[i-2]=='0'||str[i-2]>='3'){
                cout<<'0'<<'\n';
                return;
            }
            else{
                dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
            }
        }
        else{
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
            string tmp="";
            tmp+=str[i-2];
            tmp+=str[i-1];
            if(tmp<="26"&&tmp[0]>='1'){
                dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
            }
        }
    }
    cout<<(dp[len][0]+dp[len][1])%mod<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    input();
    solution();

    return 0;
}