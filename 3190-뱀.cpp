#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
}dat;
int where;
int my[4]={-1,0,1,0};
int mx[4]={0,1,0,-1};

int N,K,y,x,t,L;
char m;
int cnt=1;
bool eflag=false;

int input[101][101];
deque<dat> snake;
bool chk(int ny,int nx){
    if(ny<1||nx<1||ny>N||nx>N||input[ny][nx]==3)
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(input,0,sizeof(input));
    snake.push_front({1,1});
    where=1;
    input[1][1]=3;
    cin>>N;

    cin>>K;
    while(K--){
        cin>>y>>x;
        input[y][x]=1;
    }
    cin>>L;
    while(L--){
        cin>>t>>m;
        int ny;
        int nx;
        for(;cnt<=t;cnt++){
            ny=snake.front().y+my[where];
            nx=snake.front().x+mx[where];
            if(chk(ny,nx)){
                eflag=true;
                break;
            }
            snake.push_front({ny,nx});
            if(input[ny][nx]==0){
                input[snake.back().y][snake.back().x]=0;
                snake.pop_back();
            }
            input[ny][nx]=3;
        }
        if(eflag)
            break;
        switch (m) {
            case 'L':
                where=(where+3)%4;
                break;
            case 'D':
                where=(where+1)%4;
                break;
        }
    }
    if(!eflag)
        cnt--;
    while(!eflag){
        int ny=snake.front().y+my[where];
        int nx=snake.front().x+mx[where];
        cnt++;
        if(chk(ny,nx)){
            break;
        }
        snake.push_front({ny,nx});
        if(input[ny][nx]==0){
            input[snake.back().y][snake.back().x]=0;
            snake.pop_back();
        }
        input[ny][nx]=3;
    }
    cout<<cnt<<'\n';

    return 0;
}
