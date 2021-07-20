#include<bits/stdc++.h>

using namespace std;

int N;
long long X;
long long patty[51];
long long bun[51];

long long dfs(int n, long long x){
    if(n==0){
        if(x==1)
            return 1;
        else if(x==0)
            return 0;
    }

    if(x==1)
        return 0;
    else if(x<=1+bun[n-1])
        return dfs(n-1,x-1);
    else if(x==2+bun[n-1])
        return patty[n-1]+1;
    else if(x<=2+bun[n-1]*2)
        return patty[n-1]+1+dfs(n-1,x-2-bun[n-1]);
    else
        return patty[n-1]*2+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>X;
    patty[0]=1;
    bun[0]=1;
    for(int i=1;i<=N;i++){
        patty[i]=patty[i-1]*2+1;
        bun[i]=bun[i-1]*2+3;
    }

    cout<<dfs(N,X);
    return 0;
}