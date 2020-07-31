#include<bits/stdc++.h>

using namespace std;

int R,C,N;
bool where=true;
int l,c;
char input[101][101];
vector<pair<int, int> > block;
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};
int cnt;

void dfs(int y, int x){
    for(int i=0;i<4;i++){
        int ny=y+my[i];
        int nx=x+mx[i];

        if(ny<1||nx<1||ny>R||nx>C)
            continue;
        if(input[ny][nx]=='x'){
            block.push_back({ny,nx});
            input[ny][nx]='.';
            dfs(ny,nx);
        }
    }
}

bool chk(){
    for (auto it : block) {
        int ny=it.first-cnt;
        int nx=it.second;
        if(ny==1||(ny>1&&input[ny-1][nx]=='x')){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>R>>C;
    memset(input,0,sizeof(input));
    for(int y=R;y>=1;y--){
        for(int x=1;x<=C;x++){
            cin>>input[y][x];
        }
    }

    cin>>N;
    while(N--){
        cin>>l;
        if(where){//좌측
            for(c=1;c<=C;c++){
                if(input[l][c]=='x'){
                    input[l][c]='.';
                    break;
                }
            }
            where=false;
        }
        else{//우측
            for(c=C;c>=1;c--){
                if(input[l][c]=='x'){
                    input[l][c]='.';
                    break;
                }
            }
            where=true;
        }


        for(int i=0;i<4;i++){
            int ny=l+my[i];
            int nx=c+mx[i];
            if(ny<1||nx<1||ny>R||nx>C)
                continue;
            if(input[ny][nx]=='x'){
                cnt=0;
                block.clear();
                block.push_back({ny,nx});
                input[ny][nx]='.';
                dfs(ny,nx);
                while(!block.empty()){
                    if (chk())
                        break;
                    cnt++;
                }
                for (auto it : block) {
                    int ny=it.first;
                    int nx=it.second;
                    input[ny-cnt][nx]='x';
                }
            }
        }

    }


    for(int y=R;y>=1;y--){
        for(int x=1;x<=C;x++){
            cout<<input[y][x];
        }
        cout<<'\n';
    }

    return 0;
}
