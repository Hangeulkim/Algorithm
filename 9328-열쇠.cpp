#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
}dat;

int T,h,w,ret=0;
char input[110][110];
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

void bfs(){
    bool visit[110][110]={false,};
    queue<dat> q;
    q.push({0,0});

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny>=0&&nx>=0&&ny<=h+1&&nx<=w+1&&!visit[ny][nx]&&input[ny][nx]!='*'){
                if(input[ny][nx]>='A'&&input[ny][nx]<='Z')
                    continue;
                if(input[ny][nx]>='a'&&input[ny][nx]<='z'){
                    memset(visit,false,sizeof(visit));
                    for(int i=1;i<=h;i++){
                        for(int j=1;j<=w;j++){
                            if(input[i][j]==input[ny][nx]-'a'+'A'||input[i][j]==input[ny][nx]){
                                if(i==ny&&j==nx)
                                    continue;
                                input[i][j]='.';
                            }
                        }
                    }
                    input[ny][nx]='.';
                    while(!q.empty())
                        q.pop();
                }

                else if(input[ny][nx]=='$'){
                    ret++;
                    input[ny][nx]='.';
                }

                q.push({ny,nx});
                visit[ny][nx]=true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while (T--) {
        string keys;
        memset(input,'.',sizeof(input));
        ret=0;
        cin>>h>>w;
        for(int y=1;y<=h;y++){
            for(int x=1;x<=w;x++){
                cin>>input[y][x];
            }
        }
        cin>>keys;
        for(int i=0;i<keys.length();i++){
            if(keys[i]=='0') break;
            for(int y=1;y<=h;y++){
                for(int x=1;x<=w;x++){
                    if(input[y][x]==keys[i]-'a'+'A'||input[y][x]==keys[i]){
                        input[y][x]='.';
                    }
                }
            }
        }
        bfs();
        cout<<ret<<'\n';
    }

    return 0;
}
