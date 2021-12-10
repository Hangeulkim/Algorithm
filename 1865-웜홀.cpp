#include<bits/stdc++.h>

using namespace std;

typedef struct data{
    int s,e,t;
}Dat;

int tc,N,M,W;
int dist[501];

bool belford(vector<Dat> way){
    dist[1]=0;
    
    int s,e,t;

    for(int i=1;i<N;i++){
        for(auto it : way){
            s=it.s;
            e=it.e;
            t=it.t;
            dist[e]=min(dist[e],dist[s]+t);
        }
    }
    for(auto it : way){
            s=it.s;
            e=it.e;
            t=it.t;
            if(dist[e] > dist[s]+t)
                return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>N>>M>>W;

        vector<Dat> way;

        fill(&dist[0],&dist[N+1],87654321);

        int S,E,T;
        while(M--){
            cin>>S>>E>>T;
            way.push_back({S,E,T});
            way.push_back({E,S,T});
        }

        while(W--){
            cin>>S>>E>>T;
            way.push_back({S,E,-T});
        }

        if(belford(way))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }


    return 0;
}