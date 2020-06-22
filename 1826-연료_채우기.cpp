#include<bits/stdc++.h>

using namespace std;

int N,L,P,a,b;
vector<pair<int, int> > input;
int cnt=0;

bool find(){
    int idx=0;
    priority_queue<int> pq;

    while(1){
        if(P>=L)
            return true;
        while(idx<N&&input[idx].first<=P)
            pq.push(input[idx++].second);

        if(pq.empty()) return false;

        P+=pq.top();
        pq.pop();
        cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>a>>b;
        input.push_back(make_pair(a,b));
    }

    cin>>L>>P;
    sort(input.begin(),input.end());

    if(find())
        cout<<cnt<<'\n';
    else
        cout<<-1<<'\n';

    return 0;
}
