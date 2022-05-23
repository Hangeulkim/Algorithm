#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Dat{
    int s,d,z;
}dat;

int my[5]={0,-1,1,0,0};
int mx[5]={0,0,0,1,-1};

dat pan[101][101];
int R,C,M;

int fishing(int x){
    int ans=0;
    for(int i=1;i<=R;i++){
        if(pan[i][x].z > 0){
            ans=pan[i][x].z;
            pan[i][x]={0,0,0};
            break;
        }
    }
    return ans;
}

void move_shark(){
    dat tmp[101][101];
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            tmp[i][j]={0,0,0};

   for(int i=1;i<=R;i++){
       for(int j=1;j<=C;j++){
           if(pan[i][j].d){
               int mv = pan[i][j].s;
               int td = pan[i][j].d;
               if(td<=2){
                    mv%=(R-1)*2;

                    int ny=i;
                    while(mv--){
                        if((ny==1&&td==1)||(ny==R&&td==2))
                            td=td==1?2:1;
                        ny+=my[td];
                    }

                    if(tmp[ny][j].z != 0){
                        if(tmp[ny][j].z < pan[i][j].z)
                            tmp[ny][j]={pan[i][j].s,td,pan[i][j].z};
                    }
                    else{
                        tmp[ny][j]={pan[i][j].s,td,pan[i][j].z};
                    }
               }
               else{
                    mv%=(C-1)*2;

                    int nx=j;
                    while(mv--){
                        if((nx==1&&td==4)||(nx==C&&td==3))
                            td=td==3?4:3;
                        nx+=mx[td];
                    }

                    if(tmp[i][nx].z != 0){
                        if(tmp[i][nx].z < pan[i][j].z)
                            tmp[i][nx]={pan[i][j].s,td,pan[i][j].z};
                    }
                    else{
                        tmp[i][nx]={pan[i][j].s,td,pan[i][j].z};
                    }
               }
           }
           pan[i][j]={0,0,0};
       }
   }
   for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            pan[i][j]=tmp[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x=0;
    int ret=0;
    int r,c,s,d,z;

    cin>>R>>C>>M;
    
    while(M--){
        cin>>r>>c>>s>>d>>z;
        pan[r][c]={s,d,z};
    }

    while(x<=C){
        x++;
        ret+=fishing(x);
        move_shark();
    }

    cout<<ret<<'\n';
    return 0;
}