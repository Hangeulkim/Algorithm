#include<bits/stdc++.h>

using namespace std;

long long T;
int N;
vector<int> result;
vector<int> input;

bool bs(long long mid){
    long long cnt=0;
    vector<int> chk;
    long long tmp;

    chk.assign(input.begin(),input.end());

    for(int i=0;i<N-1;i++){
        tmp=chk[i+1]-chk[i];
        if(tmp>mid){
            cnt+=tmp-mid;
            chk[i+1]=chk[i]+mid;
        }
    }

    for(int i=N-1;i>0;i--){
        tmp=chk[i-1]-chk[i];
        if(tmp>mid){
            cnt+=tmp-mid;
            chk[i-1]=chk[i]+mid;
        }
    }

    if(cnt>T)
        return false;

    result.assign(chk.begin(),chk.end());
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>T;
    int tmp;

    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    long long l=0,r=1e9;

    while(l<=r){
        long long mid=(l+r)/2;

        if(bs(mid))
            r=mid-1;
        else
            l=mid+1;
    }

    for(int i=0;i<N;i++){
        cout<<result[i]<<" ";
    }
    cout<<'\n';

    return 0;
}
