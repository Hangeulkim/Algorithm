#include<bits/stdc++.h>

using namespace std;

typedef struct St{
    int y;
    int x;
    int cnt;
    int fire;
}st;

string tmp;
vector<string> input;
int N,M;
queue<st> bfs_arr;
int chk[1001][1001][2]={0,};

void bfs(){
    bfs_arr.push({0,0,1,0});
    chk[0][0][0]=1;

    while(!bfs_arr.empty()){
        int tmp_y=bfs_arr.front().y;
        int tmp_x=bfs_arr.front().x;
        int tmp_cnt=bfs_arr.front().cnt;
        int tmp_fire=bfs_arr.front().fire;

        if(tmp_y==N-1&&
            tmp_x==M-1) break;


        if(tmp_y+1<N){
            if(input[tmp_y+1][tmp_x]=='1'&&!chk[tmp_y+1][tmp_x][1]){
                if(!tmp_fire){
                    bfs_arr.push({tmp_y+1,tmp_x,tmp_cnt+1,1});
                    chk[tmp_y+1][tmp_x][1]=1;
                }
            }
            else if(!chk[tmp_y+1][tmp_x][tmp_fire]){
                bfs_arr.push({tmp_y+1,tmp_x,tmp_cnt+1,tmp_fire});
                chk[tmp_y+1][tmp_x][tmp_fire]=1;
            }
        }

        if(tmp_y-1>=0){
            if(input[tmp_y-1][tmp_x]=='1'&&!chk[tmp_y-1][tmp_x][1]){
                if(!tmp_fire){
                    bfs_arr.push({tmp_y-1,tmp_x,tmp_cnt+1,1});
                    chk[tmp_y-1][tmp_x][1]=1;
                }
            }
            else if(!chk[tmp_y-1][tmp_x][tmp_fire]){
                bfs_arr.push({tmp_y-1,tmp_x,tmp_cnt+1,tmp_fire});
                chk[tmp_y-1][tmp_x][tmp_fire]=1;
            }
        }


        if(tmp_x+1<M){
            if(input[tmp_y][tmp_x+1]=='1'&&!chk[tmp_y][tmp_x+1][1]){
                if(!tmp_fire){
                    bfs_arr.push({tmp_y,tmp_x+1,tmp_cnt+1,1});
                    chk[tmp_y][tmp_x+1][1]=1;
                }
            }
            else if(!chk[tmp_y][tmp_x+1][tmp_fire]){
                bfs_arr.push({tmp_y,tmp_x+1,tmp_cnt+1,tmp_fire});
                chk[tmp_y][tmp_x+1][tmp_fire]=1;
            }
        }


        if(tmp_x-1>=0){
            if(input[tmp_y][tmp_x-1]=='1'&&!chk[tmp_y][tmp_x-1][1]){
                if(!tmp_fire){
                    bfs_arr.push({tmp_y,tmp_x-1,tmp_cnt+1,1});
                    chk[tmp_y][tmp_x-1][1]=1;
                }
            }
            else if(!chk[tmp_y][tmp_x-1][tmp_fire]){
                bfs_arr.push({tmp_y,tmp_x-1,tmp_cnt+1,tmp_fire});
                chk[tmp_y][tmp_x-1][tmp_fire]=1;
            }
        }


        bfs_arr.pop();
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
