#include<bits/stdc++.h>

using namespace std;

int N;
int input[21][21];
int result=0;

void move(int m){
    bool visit[21][21]={false,};
    switch (m) {
        case 0://위
            for(int x=1;x<=N;x++){
                for(int y=2;y<=N;y++){
                    if(input[y][x]==0)
                        continue;
                    else{
                        int k=y;
                        for(k=y;k>1;k--){
                            if(input[k-1][x]==0){
                                if(visit[k][x]){
                                    visit[k-1][x]=true;
                                    visit[k][x]=false;
                                }
                                input[k-1][x]=input[k][x];
                                input[k][x]=0;
                            }
                            else if(input[k][x]==input[k-1][x]&&!visit[k-1][x]&&!visit[k][x]){
                                input[k-1][x]*=2;
                                input[k][x]=0;
                                visit[k-1][x]=true;
                            }
                            else
                                break;
                        }
                    }
                }
            }
            break;
        case 1://아래
            for(int x=1;x<=N;x++){
                for(int y=N-1;y>=1;y--){
                    if(input[y][x]==0)
                        continue;
                    else{
                        int k=y;
                        for(k=y;k<N;k++){
                            if(input[k+1][x]==0){
                                if(visit[k][x]){
                                    visit[k+1][x]=true;
                                    visit[k][x]=false;
                                }
                                input[k+1][x]=input[k][x];
                                input[k][x]=0;
                            }
                            else if(input[k][x]==input[k+1][x]&&!visit[k+1][x]&&!visit[k][x]){
                                input[k+1][x]*=2;
                                input[k][x]=0;
                                visit[k+1][x]=true;
                            }
                            else
                                break;
                        }
                    }
                }
            }
            break;
        case 2://오른쪽
            for(int y=1;y<=N;y++){
                for(int x=N-1;x>=1;x--){
                    if(input[y][x]==0)
                        continue;
                    else{
                        int k=x;
                        for(k=x;k<N;k++){
                            if(input[y][k+1]==0){
                                if(visit[y][k]){
                                    visit[y][k+1]=true;
                                    visit[y][k]=false;
                                }
                                input[y][k+1]=input[y][k];
                                input[y][k]=0;
                            }
                            else if(input[y][k]==input[y][k+1]&&!visit[y][k+1]&&!visit[y][k]){
                                input[y][k+1]*=2;
                                input[y][k]=0;
                                visit[y][k+1]=true;
                            }
                            else
                                break;
                        }
                    }
                }
            }
            break;
        case 3://왼쪽
            for(int y=1;y<=N;y++){
                for(int x=2;x<=N;x++){
                    if(input[y][x]==0)
                        continue;
                    else{
                        int k=x;
                        for(k=x;k>1;k--){
                            if(input[y][k-1]==0){
                                if(visit[y][k]){
                                    visit[y][k-1]=true;
                                    visit[y][k]=false;
                                }
                                input[y][k-1]=input[y][k];
                                input[y][k]=0;
                            }
                            else if(input[y][k]==input[y][k-1]&&!visit[y][k-1]&&!visit[y][k]){
                                input[y][k-1]*=2;
                                input[y][k]=0;
                                visit[y][k-1]=true;
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
            break;
    }
}

void dfs(int cnt){
    if(cnt==5){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                result=max(result,input[i][j]);
            }
        }
        return;
    }

    int c[21][21];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            c[i][j]=input[i][j];
        }
    }

    for(int i=0;i<4;i++){
        move(i);
        dfs(cnt+1);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                input[i][j]=c[i][j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
        }
    }

    dfs(0);
    cout<<result<<'\n';

    return 0;
}
