#include<bits/stdc++.h>

using namespace std;

int N,M;
long long A;
long long tmp[1010];
long long result=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    memset(tmp,0,sizeof(tmp));
    long long num=0;
    for(int i=1;i<=N;i++){
        cin>>A;
        num=(A+num)%M;
        if(!num) result++;
        tmp[num]++;
    }
    for(int i=0;i<M;i++){
        if(tmp[i]!=0) result += tmp[i] * (tmp[i]-1) / 2;
    }
    cout<<result<<'\n';

    return 0;
}
