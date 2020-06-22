#include<bits/stdc++.h>

using namespace std;

typedef struct bridge{
    int end;
    int cost;
}brd;

int N,M,a,b,c,result;
vector<brd> input[10001];
int fact1,fact2;
int btm=1,top=0;
bool chk[10001];


bool bfs(int mid){
    queue<int> q;
    chk[fact1]=true;
    q.push(fact1);

    while(!q.empty()){
        int from=q.front();
        q.pop();

        for(int i=0;i<input[from].size();i++){
            if(!chk[input[from][i].end]&&input[from][i].cost>=mid){
                q.push(input[from][i].end);
                chk[input[from][i].end]=true;
            }
        }

        if(chk[fact1]&&chk[fact2])
            return true;
    }


    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        if(a==b) continue;
        input[a].push_back({b,c});
        input[b].push_back({a,c});
        top=max(top,c);
    }
    cin>>fact1>>fact2;


    while(top>=btm){
        int mid=(top+btm)/2;
        fill(chk,chk+10001,false);

        if(bfs(mid)){
            btm=mid+1;
            result=max(result,mid);
        }
        else{
            top=mid-1;
        }
    }
    cout<<result<<'\n';

    return 0;
}
