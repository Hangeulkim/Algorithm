#include<iostream>
#include<queue>

using namespace std;

int R,C;
char arr[1001][1001];
int my[4] = {0,1,0,-1};
int mx[4] = {1,0,-1,0};
bool chk[1001][1001];
queue<pair<int, int> > q, fq;

void input(){
    cin>>R>>C;

    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cin>>arr[i][j];
            if(arr[i][j]=='J'){
                q.push({i,j});
                chk[i][j]=true;
                arr[i][j]='.';
            }
            else if(arr[i][j]=='F'){
                fq.push({i,j});
            }
        }
    }
}

void spread(){
    queue<pair<int, int> > tq;

    while(!fq.empty()){
        int y = fq.front().first;
        int x = fq.front().second;

        fq.pop();
        
        for(int i=0;i<4;++i){
            int ny = y + my[i];
            int nx = x + mx[i];

            if(y<0||x<0||x>=C||y>=R||arr[ny][nx]!='.')
                continue;

            arr[ny][nx]='F';
            tq.push({ny,nx});
        }
    }

    fq = tq;
}

bool bfs(){
    queue<pair<int, int> > tq;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        if(y<=0||x<=0||x>=C-1||y>=R-1)
            return true;

        for(int i=0;i<4;++i){
            int ny = y + my[i];
            int nx = x + mx[i];

            if(y<0||x<0||x>=C||y>=R||arr[ny][nx]!='.'||chk[ny][nx])
                continue;

            chk[ny][nx]=true;
            tq.push({ny,nx});
        }
    }

    q = tq;
    return false;
}

void solution(){
    int cnt = 0;
    
    while(!q.empty()){
        spread();
        if(bfs()){
            cout<<cnt+1<<'\n';
            return;
        }
        ++cnt;
    }
    cout<<"IMPOSSIBLE"<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}