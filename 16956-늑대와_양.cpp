#include<bits/stdc++.h>

using namespace std;

int R,C;
char input[501][501];
bool chk[501][501];
int mv[4][2]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

queue<pair<int, int> > s,w;

int bfs(){
    while(!s.empty()){
        int y,x;
        tie(y,x) = s.front();
        
        s.pop();
        for(int m=0;m<4;m++){
            int ny=y+mv[m][0];
            int nx=x+mv[m][1];

            if(ny<0||nx<0||ny>=R||nx>=C||input[ny][nx]!='.')
                continue;
            
            input[ny][nx]='D';
        }
    }

    while(!w.empty()){
        int y,x;
        tie(y,x) = w.front();

        w.pop();

        if(input[y][x]=='S')
            return 0;

        for(int m=0;m<4;m++){
            int ny=y+mv[m][0];
            int nx=x+mv[m][1];

            if(ny<0||nx<0||ny>=R||nx>=C||chk[ny][nx]||input[ny][nx]=='D')
                continue;
            
            chk[ny][nx]=true;
            w.push({ny,nx});
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
            if(input[i][j]=='W'){
                w.push({i,j});
                chk[i][j]=true;
            }
                
            else if(input[i][j]=='S')
                s.push({i,j});
        }
    }
    
    int num=bfs();
    cout<<num<<'\n';
    if(num==1){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<input[i][j];
            }
            cout<<'\n';
        }
    }

    return 0;
}