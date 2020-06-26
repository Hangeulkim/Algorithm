#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> input;
vector<int> op;
long long maxn=-9876543210,minn=9876543210;

void find(int p, int m, int d, int mu, int idx, long long sum){
    if(idx==N){
        maxn=max(maxn,sum);
        minn=min(minn,sum);
        return;
    }

    if(p<op[0]) find(p+1,m,d,mu,idx+1,sum+input[idx]);
    if(m<op[1]) find(p,m+1,d,mu,idx+1,sum-input[idx]);
    if(d<op[3]) find(p,m,d+1,mu,idx+1,sum/input[idx]);
    if(mu<op[2]) find(p,m,d,mu+1,idx+1,sum*input[idx]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    for(int i=0;i<4;i++){
        cin>>tmp;
        op.push_back(tmp);
    }

    find(0,0,0,0,1,input[0]);
    cout<<maxn<<'\n'<<minn<<'\n';

    return 0;
}
