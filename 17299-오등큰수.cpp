#include<bits/stdc++.h>

using namespace std;

int N,tmp;
stack<pair<int, int> > s;
int input[1000001];
int cnt[1000001];
int result[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    memset(cnt,0,sizeof(cnt));
    memset(result,-1,sizeof(result));
    for(int i=0;i<N;i++){
        cin>>input[i];
        cnt[input[i]]++;
    }

    for(int i=0;i<N;i++){
        while(!s.empty() && cnt[input[i]] > cnt[s.top().first]){
            result[s.top().second]=input[i];
            s.pop();
        }
        s.push({input[i],i});
    }

    for(int i=0;i<N;i++)
        cout<<result[i]<<" ";

    return 0;
}
