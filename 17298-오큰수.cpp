#include<bits/stdc++.h>

using namespace std;

int N,tmp;
stack<pair<int, int> > s;
int result[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        result[i]=-1;

        while(!s.empty() && tmp > s.top().first){
            result[s.top().second]=tmp;
            s.pop();
        }
        s.push({tmp,i});
    }

    for(int i=0;i<N;i++)
        cout<<result[i]<<" ";

    return 0;
}
