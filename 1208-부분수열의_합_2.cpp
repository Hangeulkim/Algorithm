#include<bits/stdc++.h>

using namespace std;

int N,S,endn;
long long result=0;
int input[41];
int m[4000001];

void dfsl(int idx, int num){
    if(idx==endn){
        m[num+2000000]++;
        return ;
    }

    dfsl(idx+1,num);
    dfsl(idx+1,num+input[idx]);
}

void dfsr(int idx, int num){
    if(idx==N+1){
        int s=S-num+2000000;
        if(s<0||s>4000000)
            return ;
        result+=m[s];
        return;
    }

    dfsr(idx+1,num);
    dfsr(idx+1,num+input[idx]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>S;
    for(int i=1;i<=N;i++){
        cin>>input[i];
    }

    endn=N/2+1;
    dfsl(1,0);
    dfsr(endn,0);
    if(S==0)    result--;
    cout<<result<<'\n';

    return 0;
}
