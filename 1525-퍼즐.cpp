#include<bits/stdc++.h>

using namespace std;

int input=0,tmp;
map<int, bool> visit;
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

int chk(int a, int dy, int dx){
    int arr[4][4],ret=0,ny,nx;

    for(int y=3;y>=1;y--){
        for(int x=3;x>=1;x--){
            arr[y][x]=a%10;
            if(arr[y][x]==9){
                ny=y;
                nx=x;

                if(ny+dy<1||nx+dx<1||ny+dy>3||nx+dx>3)
                    return 0;
            }
            a/=10;
        }
    }

    tmp=arr[ny][nx];
    arr[ny][nx]=arr[ny+dy][nx+dx];
    arr[ny+dy][nx+dx]=tmp;

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            ret=ret*10+arr[i][j];
        }
    }

    return ret;
}

int bfs(){
    queue<pair<int, int> > q;

    q.push({input,0});

    while(!q.empty()){
        int num=q.front().first;
        int cnt=q.front().second;

        q.pop();
        if(num==123456789)
            return cnt;

        for(int i=0;i<4;i++){
            int chk_num=chk(num,my[i],mx[i]);

            if(visit.count(chk_num)==0&&chk_num!=0){
                q.push({chk_num,cnt+1});
                visit[chk_num]=true;
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=9;i++){
        cin>>tmp;
        if(tmp==0)
            tmp=9;
        input=input*10+tmp;
    }
    cout<<bfs();

    return 0;
}
