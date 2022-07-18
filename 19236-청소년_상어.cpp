#include<iostream>
#include<vector>

using namespace std;

bool chk[16];
int m[10][2]={
    {0,0},
    {-1,0},
    {-1,-1},
    {0,-1},
    {1,-1},
    {1,0},
    {1,1},
    {0,1},
    {-1,1}
};

int ret=0;
int arr[4][4];
int mdat[20][3];

void show(int fish[4][4], int dat[20][3]){
    cout<<'\n';
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<fish[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

/*
    for(int i=0;i<17;i++){
        for(int j=0;j<3;j++){
            cout<<dat[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    */
}

void fish_move(int fish[4][4],int dat[20][3]){
    for(int i=1;i<17;i++){
        if(!dat[i][2])
            continue;
        
        int y=dat[i][0];
        int x=dat[i][1];
        while (1)
        {
            int ny=y+m[dat[i][2]][0];
            int nx=x+m[dat[i][2]][1];

            if(ny<0||nx<0||ny>=4||nx>=4||fish[ny][nx]==-1){
                dat[i][2]=(dat[i][2])%8+1;
                continue;
            }

            if(fish[ny][nx]){
                int nn=fish[ny][nx];
                swap(fish[ny][nx],fish[y][x]);
                swap(dat[i][0],dat[nn][0]);
                swap(dat[i][1],dat[nn][1]);

                break;
            }
            else{
                swap(fish[ny][nx],fish[y][x]);
                dat[i][0]=ny;
                dat[i][1]=nx;

                break;
            }
        }
    }
}

void dfs(int y, int x, int cnt, int fish[4][4], int dat[20][3]){
    int tfish[4][4], tdat[20][3];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            tfish[i][j]=fish[i][j];

    for(int i=0;i<20;i++)
        for(int j=0;j<3;j++)
            tdat[i][j]=dat[i][j];

    fish_move(tfish,tdat);

    int ny=y;
    int nx=x;
    tfish[y][x]=0;
    int tm=dat[0][2];
    while(1){
        ny+=m[tdat[0][2]][0];
        nx+=m[tdat[0][2]][1];
        int tmp=tfish[ny][nx];

        if(ny<0||nx<0||ny>=4||nx>=4)
            break;
        
        if(!tfish[ny][nx])
            continue;

        tfish[ny][nx]=-1;
        tfish[y][x]=0;
        tdat[0][2]=tdat[tmp][2];
        tdat[tmp][2]=0;
        
        dfs(ny,nx,cnt+tmp,tfish,tdat);

        tfish[ny][nx]=tmp;
        tfish[y][x]=-1;
        tdat[tmp][2]=tdat[0][2];
        tdat[0][2]=tm;
    }
    ret=max(ret,cnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j]>>mdat[arr[i][j]][2];
            mdat[arr[i][j]][0]=i;
            mdat[arr[i][j]][1]=j;
        }
    }

    mdat[0][2]=mdat[arr[0][0]][2];
    mdat[arr[0][0]][2]=0;
    ret+=arr[0][0];
    arr[0][0]=-1;
    dfs(0,0,ret,arr,mdat);

    cout<<ret<<'\n';
    return 0;
}