#include<bits/stdc++.h>

using namespace std;

int N,K,D;
int Delay[1001];
vector<int> way[1001];
int inDegree[1001];
int result[1001];

int topologySort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            q.push(i);
            result[i]=Delay[i];
        }
    }


    for(int i=1;i<=N;i++){
        int f=q.front();
        q.pop();

        if(f==D){
            return result[D];
        }

        for(int j=0;j<way[f].size();j++){
            int y=way[f][j];
            inDegree[y]--;
            result[y]=max(result[y],result[f]+Delay[y]);
            if(inDegree[y]==0){
                q.push(y);
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    int X,Y;
    cin>>T;
    while(T--){
        cin>>N>>K;

        for(int i=1;i<=N;i++){
            cin>>Delay[i];
            inDegree[i]=0;
            result[i]=0;
            way[i].clear();
        }

        for(int i=1;i<=K;i++){
            cin>>X>>Y;
            inDegree[Y]++;
            way[X].push_back(Y);
        }
        cin>>D;
        cout<<topologySort()<<'\n';
    }

    return 0;
}
