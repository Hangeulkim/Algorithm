#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y,x,d,m;
}dat;

int input[10][10];
int tmp[10][10];
int N,M,ny,nx;
int result=0;

vector<dat> cctv;

int my[4]={-1,0,1,0};
int mx[4]={0,1,0,-1};

void find(){
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            tmp[i][j]=input[i][j];
        }
    }

    for(int i=0;i<cctv.size();i++){
        switch (cctv[i].d) {
            case 1:
            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[cctv[i].m];
                nx+=mx[cctv[i].m];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            break;

            case 2:
            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[cctv[i].m];
                nx+=mx[cctv[i].m];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+2)%4];
                nx+=mx[(cctv[i].m+2)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            break;

            case 3:
            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[cctv[i].m];
                nx+=mx[cctv[i].m];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+1)%4];
                nx+=mx[(cctv[i].m+1)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            break;

            case 4:
            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[cctv[i].m];
                nx+=mx[cctv[i].m];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+1)%4];
                nx+=mx[(cctv[i].m+1)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+3)%4];
                nx+=mx[(cctv[i].m+3)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            break;

            case 5:
            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[cctv[i].m];
                nx+=mx[cctv[i].m];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+2)%4];
                nx+=mx[(cctv[i].m+2)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+3)%4];
                nx+=mx[(cctv[i].m+3)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            ny=cctv[i].y;
            nx=cctv[i].x;
            while(1){
                ny+=my[(cctv[i].m+1)%4];
                nx+=mx[(cctv[i].m+1)%4];

                if(tmp[ny][nx]==6){
                    break;
                }

                tmp[ny][nx]=-1;
            }

            break;

        }
    }

    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(tmp[i][j]==0)
                cnt++;
        }
    }

    result=min(result,cnt);
}

void dfs(int num){
    if(num >= cctv.size()){
        find();
        return;
    }

    for(int i=0;i<4;i++){
        cctv[num].m=i;
        dfs(num+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            if(i==0||j==0||i==N+1||j==M+1){
                input[i][j]=6;
            }
            else{
                cin>>input[i][j];
            }
            if(input[i][j]!=0&&input[i][j]!=6){
                cctv.push_back({i,j,input[i][j],0});
            }
            else if(input[i][j]==0)
                result++;
        }
    }

    if(cctv.size()>0){
        for(int i=0;i<4;i++){
            cctv[0].m=i;
            dfs(1);
        }
    }

    cout<<result<<'\n';

    return 0;
}
