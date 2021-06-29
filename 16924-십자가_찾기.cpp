#include<bits/stdc++.h>

using namespace std;

typedef struct Dat{
    int y;
    int x;
    int s;
}dat;

int mv[4][2]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

int N,M;

bool chk[101][101];
bool ans[101][101];
char input[101][101];

vector<dat> arr;

int bfs(){
    queue<pair<int, int> > q;

    q.push({0,0});
    chk[0][0]=true;

    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();

        q.pop();

        int num=987654321;
        for(int i=0;i<4;i++){
            int ny=y+mv[i][0];
            int nx=x+mv[i][1];

            if(ny<0||nx<0||ny>=N||nx>=M){
                num=0;
                continue;
            }
                
            if(!chk[ny][nx]){
                chk[ny][nx]=true;
                q.push({ny,nx});
            }
            
            if(input[y][x]=='.'){
                num=0;
                continue;
            }
            
            int cnt=0;
            while(ny>=0&&nx>=0&&ny<N&&nx<M&&input[ny][nx]=='*'){
                cnt++;
                ny+=mv[i][0];
                nx+=mv[i][1];
            }
            num=min(cnt,num);
        }

        if(num>0){
            ans[y][x]=true;
            for(int i=0;i<4;i++){
                int ny=y;
                int nx=x;

                for(int j=0;j<num;j++){
                    ny+=mv[i][0];
                    nx+=mv[i][1];
                    ans[ny][nx]=true;
                }
            }
            arr.push_back({y+1,x+1,num});
        }
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(input[i][j]=='*'&&!ans[i][j])
                return -1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>input[i][j];
        }
    }

    if(bfs()==-1||arr.size()>N*M)
        cout<<-1;
    else{
        cout<<arr.size()<<'\n';
        for(auto it : arr){
            cout<<it.y<<" "<<it.x<<" "<<it.s<<'\n';
        }
    }

    return 0;
}