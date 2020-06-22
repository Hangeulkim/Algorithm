#include<bits/stdc++.h>

using namespace std;

int N,tmp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    priority_queue<int,vector<int>,less<int> > maxH;
    priority_queue<int,vector<int>,greater<int> > minH;
    while(N--){
        cin>>tmp;
        if(maxH.size()>minH.size()) minH.push(tmp);
        else maxH.push(tmp);
        if(!maxH.empty()&&!minH.empty()&&minH.top()<maxH.top()){
            int maxT=maxH.top(),minT=minH.top();
            maxH.pop();
            minH.pop();
            maxH.push(minT);
            minH.push(maxT);
        }
        cout<<maxH.top()<<'\n';
    }


    return 0;
}
