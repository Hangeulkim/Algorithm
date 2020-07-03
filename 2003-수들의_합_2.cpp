#include<bits/stdc++.h>

using namespace std;

long long part[10001];
int tmp;
int N,M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        part[i]=part[i-1]+tmp;
    }
    int l=1,r=1,cnt=0;
    while(r<=N){
        if(part[r]-part[l-1]==M)
            cnt++;
        if(part[r]-part[l-1]<=M)
            r++;
        else
            l++;
    }
    cout<<cnt<<'\n';

    return 0;
}
