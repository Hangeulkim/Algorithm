#include<bits/stdc++.h>

using namespace std;

typedef struct St{
    int y;
    int x;
    int cnt;
    int fire;
}st;

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

string tmp;
vector<string> input;
int N,M;
queue<st> bfs_arr;
int chk[2][1001][1001];

void bfs(){
    bfs_arr.push({0,0,1,0});
    chk[0][0][0]=true;

    while(!bfs_arr.empty()){
        int tmp_y=bfs_arr.front().y;
        int tmp_x=bfs_arr.front().x;
        int tmp_cnt=bfs_arr.front().cnt;
        int tmp_fire=bfs_arr.front().fire;

        if(tmp_y==N-1&&
            tmp_x==M-1) break;

        bfs_arr.pop();


        for(int i=0;i<4;i++){
            int ny=tmp_y+my[i];
            int nx=tmp_x+mx[i];

            if(ny<0||nx<0||ny>=N||nx>=M||chk[tmp_fire][ny][nx])
                continue;
            if(input[ny][nx]=='1'){
                if(tmp_fire)
                    continue;
                chk[1][ny][nx]=true;
                bfs_arr.push({ny,nx,tmp_cnt+1,1});
            }
            else{
                bfs_arr.push({ny,nx,tmp_cnt+1,tmp_fire});
                chk[tmp_fire][ny][nx]=true;
                if(tmp_fire==0)
                    chk[1][ny][nx]=true;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    bfs();

    if(bfs_arr.empty()){
        cout<<-1<<'\n';
    }
    else{
        cout<<bfs_arr.front().cnt<<'\n';
    }


    return 0;
}
