#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, int>> result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp1=0,tmp2=0,testcase=0;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>tmp1>>tmp2;
        result.push_back(make_pair(tmp1,tmp2));
    }
    sort(result.begin(),result.end());
    for(auto it=result.begin();it!=result.end();it++) cout<<it->first<<" "<<it->second<<'\n';
    return 0;
}
