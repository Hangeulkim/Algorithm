#include<bits/stdc++.h>

using namespace std;

int T,N;
int par[20001];
char where[20001];
bool Fflag=false;

void result(int num){
    if(num==-1)
        return;
    result(par[num]);
    cout<<where[num];
}

void bfs(){
    queue<int> q;
    int visit[20001]={0,};
    memset(visit,-1,sizeof(visit));

    q.push(1);
    par[1]=-1;
    visit[1]=0;
    where[1]='1';

    while(!q.empty()){
        int num=q.front();

        q.pop();

        if(visit[num]>100){
            Fflag=true;
            return;
        }

        int arr[2];
        arr[0]=(num*10)%N;
        arr[1]=(num*10+1)%N;

        for(int i=0;i<2;i++){
            if(visit[arr[i]]==-1){
                par[arr[i]]=num;
                where[arr[i]]=i+'0';

                if(arr[i]==0)
                    return;

                visit[arr[i]]=visit[num]+1;
                q.push(arr[i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>N;
        Fflag=false;
        bfs();
        if(Fflag)
            cout<<"BRAK"<<'\n';
        result(0);
        cout<<'\n';
    }

    return 0;
}
