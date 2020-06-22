#include<bits/stdc++.h>

using namespace std;

int N,K,tmp1,tmp2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    vector<pair<int,int> > jewers;
    vector<int> bags;
    priority_queue<int,vector<int>, less<int> > can;
    for(int i=0;i<N;i++){
        cin>>tmp1>>tmp2;
        jewers.push_back(make_pair(tmp1,tmp2));
    }
    for(int i=0;i<K;i++){
        cin>>tmp1;
        bags.push_back(tmp1);
    }

    sort(jewers.begin(),jewers.end());
    sort(bags.begin(),bags.end());

    long long int sum=0;
    int idx=0;

    for(int i=0;i<K;i++){
        while(idx<N&&jewers[idx].first<=bags[i]){
            can.push(jewers[idx].second);
            idx++;
        }

        if(!can.empty()){
            sum+=can.top();
            can.pop();
        }
    }

    cout<<sum<<'\n';

    return 0;
}
