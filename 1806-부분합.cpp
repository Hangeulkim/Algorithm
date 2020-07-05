#include<bits/stdc++.h>

using namespace std;

int N,S,result=987654321,tmp;
long long part[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>S;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        part[i]=part[i-1]+tmp;
    }

    int l=1,r=1;
    while(r<=N){
        if(part[r]-part[l-1]>=S){
            result=min(result,r-l+1);
            l++;
        }
        else{
            r++;
        }
    }
    if(result==987654321)
        cout<<0<<'\n';
    else
        cout<<result<<'\n';

    return 0;
}
