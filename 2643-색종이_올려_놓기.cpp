#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dp[105];
vector<pair<int, int> > list;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num=0;
    cin>>num;
    int a=0,b=0;

    for(int i=0;i<num;i++){
        cin>>a>>b;
        if(b>a) list.push_back(make_pair(b,a));
        else list.push_back(make_pair(a,b));
    }
    sort(list.begin(),list.end());


    for(int i=0;i<num;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(list[i].second>=list[j].second&&dp[i]<=dp[j]) dp[i]=dp[j]+1;
        }
    }

    cout<<*max_element(dp,dp+num)<<'\n';
    return 0;
}
