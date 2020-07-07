#include<bits/stdc++.h>

using namespace std;

int N;
int a[4001],b[4001],c[4001],d[4001];
vector<int> ab,cd;
long long cnt=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    }

    sort(cd.begin(),cd.end());

    for(auto it : ab){
        auto s=lower_bound(cd.begin(),cd.end(),-it);
        auto e=upper_bound(cd.begin(),cd.end(),-it);
        if(s==e) continue;
        cnt+=e-s;
    }

    cout<<cnt<<'\n';

    return 0;
}
