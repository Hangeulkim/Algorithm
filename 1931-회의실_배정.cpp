#include<bits/stdc++.h>

using namespace std;
int N,tmp1,tmp2,start;
vector<pair<int, int> > input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp1>>tmp2;
        input.push_back(make_pair(tmp2,tmp1));
    }
    sort(input.begin(),input.end());

    int tmp=input[0].first,cnt=1;
    for(int i=1;i<N;i++){
        if(input[i].second>=tmp){
            tmp=input[i].first;
            cnt++;
        }
    }

    cout<<cnt<<'\n';
    return 0;
}
