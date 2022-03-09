#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int N,Q;
vector<pair<int, int> > usa[5001];
bool chk[5001];

int all_usa(int v, int k){
    int cnt=0;
    queue<int> q;
    q.push(v);
    chk[v]=true;

    while(!q.empty()){
        int now=q.front();

        q.pop();

        for(int i=0;i<usa[now].size();i++){
            int next=usa[now][i].second;
            int ncnt=usa[now][i].first;

            if(chk[next])
                continue;
            
            if(ncnt>=k){
                q.push(next);
                chk[next]=true;
                cnt++;
            }   
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>Q;
    int p,q,r,k,v;
    for(int i=0;i<N-1;i++){
        cin>>p>>q>>r;
        usa[p].push_back({r,q});
        usa[q].push_back({r,p});
    }


    while(Q--){
        memset(chk,false,sizeof(chk));
        cin>>k>>v;
        cout<<all_usa(v,k)<<'\n';
    }


    return 0;
}