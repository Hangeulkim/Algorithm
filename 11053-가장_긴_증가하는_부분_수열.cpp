#include<bits/stdc++.h>
#define INF 987654321

using namespace std;

int N;
int dp[1001],tmp;
vector<int> lis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;


    lis.push_back(-INF);
    for(int i=1;i<=N;i++){
        cin>>tmp;

        if(lis.back()<tmp){
            lis.push_back(tmp);
        }
        else{
            auto it = lower_bound(lis.begin(),lis.end(),tmp);
            *it=tmp;
        }
    }
    cout<<lis.size()-1<<'\n';

    return 0;
}
