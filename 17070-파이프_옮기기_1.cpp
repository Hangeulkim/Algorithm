#include<bits/stdc++.h>

using namespace std;

typedef struct Dat{
    int y,x,m;
}dat;

int N;
int mv[3][3][2]={
    {
        {0,1},
        {0,0},
        {1,1}
    },
    {
        {0,0},
        {1,0},
        {1,1}
    },
    {
        {0,1},
        {1,0},
        {1,1}
    }
};

int arr[17][17];

int bfs(){
    int cnt=0;
    queue<dat> q;

    q.push({1,2,0});

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int m=q.front().m;

        q.pop();
        if(y==N&&x==N){
            cnt++;
            continue;
        }

        for(int i=0;i<3;i++){
            if(mv[m][i][0]==0&&mv[m][i][1]==0)
                continue;
            
            int ny=y+mv[m][i][0];
            int nx=x+mv[m][i][1];

            if(ny>N||nx>N||arr[ny][nx]==1)
                continue;
            if(i==2&&(arr[ny][nx-1]||arr[ny-1][nx]))
                continue;

            q.push({ny,nx,i});
        }
    }


    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }

    cout<<bfs();

    return 0;
}