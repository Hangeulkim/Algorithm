#include<iostream>
#include<string>

using namespace std;

int R,C;
int ans=0;
string pipes[10001];
int my[3]={-1,0,1};

void input(){
    cin>>R>>C;

    for(int i=0;i<R;++i){
        cin>>pipes[i];
    }
}

bool dfs(int y, int x){
    pipes[y][x]='X';
    if(x==C-1){
        ++ans;
        return true;
    }

    for(int i=0;i<3;++i){
        int ny=y+my[i];
        int nx=x+1;
        if(ny<0||ny>=R||pipes[ny][nx]!='.')
            continue;

        if(dfs(ny,nx))
            return true;
    }
    return false;
}

void solution(){
    for(int i=0;i<R;++i){
        dfs(i,0);
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}