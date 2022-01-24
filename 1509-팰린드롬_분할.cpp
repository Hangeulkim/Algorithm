#include<bits/stdc++.h>

using namespace std;

string input;
bool p[2501][2501];
int dp[2501];
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    
    N=input.length();
    for(int i=0;i<N;i++)    p[i][i]=true;
    

    return 0;
}