#include<bits/stdc++.h>

using namespace std;

int R,C;
int input[501][501];

typedef struct Dat{
    int y,x,cnt;
}dat;

dat gong[501][501];
queue<pair<int, int> > q;

int mv[8][2]={
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,-1},
    {0,1},
    {1,-1},
    {1,0},
    {1,1}
};

bool chk[501][501];

void bfs(){
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        int my=gong[gong[y][x].y][gong[y][x].x].y;
        int mx=gong[gong[y][x].y][gong[y][x].x].x;
        q.pop();

        if(my==y&&mx==x)
            continue;
        chk[y][x]=true;

            
        gong[y][x].y=my;
        gong[y][x].x=mx;
        gong[my][mx].cnt+=gong[y][x].cnt;
        gong[y][x].cnt=0;
        if(chk[my][mx]){
            chk[my][mx]=false;
            q.push({my,mx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
            gong[i][j]={i,j,1};
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int min_y=i;
            int min_x=j;
            for(int m=0;m<8;m++){
                int ny=i+mv[m][0];
                int nx=j+mv[m][1];

                if(ny<0||nx<0||ny>=R||nx>=C)
                        continue;

                if(input[ny][nx]<input[min_y][min_x]){
                        min_y=ny;
                        min_x=nx;
                    }
            }

            
            if(!(min_y==i&&min_x==j)){
                int my=gong[gong[min_y][min_x].y][gong[min_y][min_x].x].y;
                int mx=gong[gong[min_y][min_x].y][gong[min_y][min_x].x].x;
                gong[i][j].y=my;
                gong[i][j].x=mx;
                gong[my][mx].cnt+=gong[i][j].cnt;
                gong[i][j].cnt=0;
                q.push({min_y,min_x});
            }
        }
    }


    bfs();

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<gong[i][j].cnt<<" ";
        }
        cout<<'\n';
    }

    return 0;
}