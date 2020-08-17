#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int num[3];
}dat;

bool visit[501][501][1002];
int num[3];

int bfs(){
    queue<dat> q;

    q.push({num[0],num[1],num[2]});
    visit[num[0]][num[1]][num[2]]=true;

    while(!q.empty()){
        int a=q.front().num[0];
        int b=q.front().num[1];
        int c=q.front().num[2];

        q.pop();

        if(a==b&&b==c)
            return 1;

        if(a!=b){
            num[0]=a;
            num[1]=b;
            num[2]=c;

            num[1]=num[1]-num[0];
            num[0]=num[0]*2;
            sort(num,num+3);
            if(!visit[num[0]][num[1]][num[2]]){
                q.push({num[0],num[1],num[2]});
                visit[num[0]][num[1]][num[2]]=true;
            }
        }
        if(b!=c){
            num[0]=a;
            num[1]=b;
            num[2]=c;

            num[2]=num[2]-num[1];
            num[1]=num[1]*2;
            sort(num,num+3);
            if(!visit[num[0]][num[1]][num[2]]){
                q.push({num[0],num[1],num[2]});
                visit[num[0]][num[1]][num[2]]=true;
            }
        }
        if(a!=c){
            num[0]=a;
            num[1]=b;
            num[2]=c;

            num[2]=num[2]-num[0];
            num[0]=num[0]*2;
            sort(num,num+3);
            if(!visit[num[0]][num[1]][num[2]]){
                q.push({num[0],num[1],num[2]});
                visit[num[0]][num[1]][num[2]]=true;
            }
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    cin>>num[0]>>num[1]>>num[2];
    sort(num,num+3);
    cout<<bfs();

    return 0;
}
