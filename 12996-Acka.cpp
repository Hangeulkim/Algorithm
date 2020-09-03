#include<bits/stdc++.h>

using namespace std;

int S,D,K,H;
long long visit[51][51][51][51];

long long find(int s, int d, int k, int h){
    if(d<0||k<0||h<0)
        return 0;

    if(visit[s][d][k][h]!=-1)
        return visit[s][d][k][h];

    if(s==0){
        if(!d&&!k&&!h)
            return 1;
        return 0;
    }

    long long ret=0;

    ret+=find(s-1,d-1,k,h);
    ret+=find(s-1,d,k-1,h);
    ret+=find(s-1,d,k,h-1);
    ret+=find(s-1,d-1,k-1,h);
    ret+=find(s-1,d-1,k,h-1);
    ret+=find(s-1,d,k-1,h-1);
    ret+=find(s-1,d-1,k-1,h-1);
    ret%=1000000007;
    return visit[s][d][k][h]=ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>S>>D>>K>>H;
    memset(visit,-1,sizeof(visit));
    cout<<find(S,D,K,H);

    return 0;
}
