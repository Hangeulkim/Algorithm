#include<bits/stdc++.h>

using namespace std;

int K,V,e;
int visit[20001]={0,};
bool result;
vector<int> E[20001];

void dfs(int idx, int color){
    visit[idx]=color;

    for(int i=0;i<E[idx].size();i++){
        int next=E[idx][i];
        if(visit[next]==0){
            if(color==1){
                dfs(next,2);
            }
            else{
                dfs(next,1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp1,tmp2;
    cin>>K;
    while(K--){
        cin>>V>>e;
        memset(visit,0,sizeof(visit));

        for(int i=1;i<=V;i++){
            E[i].clear();
        }

        for(int i=0;i<e;i++){
            cin>>tmp1>>tmp2;
            E[tmp1].push_back(tmp2);
            E[tmp2].push_back(tmp1);
        }

        for(int i=1;i<=V;i++)
            if(visit[i]==0)
                dfs(i,1);

        result=true;
        for(int i=1;i<=V;i++){
            for(int j=0;j<E[i].size();j++){
                int next=E[i][j];
                if(visit[i]==visit[next]){
                    result=false;
                    break;
                }
            }
            if(!result)
                break;
        }


        if(result)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }

    return 0;
}
