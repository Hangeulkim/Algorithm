#include<bits/stdc++.h>

using namespace std;

long long N,P,Q;
map<long long, long long> dp;

long long backt(long long in){
    auto it=dp.find(in);

    if(it==dp.end()){
        dp[in]=backt(in/P)+backt(in/Q);
    }

    return dp[in];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>P>>Q;

    dp[0]=1;
    cout<<backt(N)<<'\n';

    return 0;
}
