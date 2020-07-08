#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int a,b,c;
}dat;
int A,B,C;
bool visit[201][201]={false,};
bool result[201]={false,};

void bfs(){
    queue<dat> q;

    q.push({0,0,C});
    visit[0][0]=true;
    result[C]=true;

    while(!q.empty()){
        int a=q.front().a;
        int b=q.front().b;
        int c=q.front().c;

        q.pop();

        if(a==0)
            result[c]=true;

        if(a+b>B){
            if(!visit[a+b-B][B]){
                visit[a+b-B][B]=true;
                q.push({a+b-B,B,c});
            }
        }
        else{
            if(!visit[0][a+b]){
                visit[0][a+b]=true;
                q.push({0,a+b,c});
            }
        }

        if(a+c>C){
            if(!visit[a+c-C][b]){
                visit[a+c-C][b]=true;
                q.push({a+c-C,b,C});
            }
        }
        else{
            if(!visit[0][b]){
                visit[0][b]=true;
                q.push({0,b,a+c});
            }
        }

        if(b+a>A){
            if(!visit[A][a+b-A]){
                visit[A][a+b-A]=true;
                q.push({A,a+b-A,c});
            }
        }
        else{
            if(!visit[a+b][0]){
                visit[a+b][0]=true;
                q.push({a+b,0,c});
            }
        }

        if(b+c>C){
            if(!visit[a][b+c-C]){
                visit[a][b+b-C]=true;
                q.push({a,b+c-C,C});
            }
        }
        else{
            if(!visit[a][0]){
                visit[a][0]=true;
                q.push({a,0,b+c});
            }
        }

        if(c+a>A){
            if(!visit[A][b]){
                visit[A][b]=true;
                q.push({A,b,a+c-A});
            }
        }
        else{
            if(!visit[a+c][b]){
                visit[a+c][b]=true;
                q.push({a+c,b,0});
            }
        }

        if(c+b>B){
            if(!visit[a][B]){
                visit[a][B]=true;
                q.push({a,B,c+b-B});
            }
        }
        else{
            if(!visit[a][b+c]){
                visit[a][b+c]=true;
                q.push({a,b+c,0});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B>>C;
    bfs();

    for(int i=0;i<=C;i++){
        if(result[i])
            cout<<i<<" ";
    }

    return 0;
}
