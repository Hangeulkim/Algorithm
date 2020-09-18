#include<bits/stdc++.h>

using namespace std;

int N;
char input[52][52];
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};
int result=0;

void find(int y, int x, char c){
    int ny=y+my[0];
    int nx=x+mx[0];
    int cnt=1;
    while(input[ny][nx]==c){
        cnt++;
        ny+=my[0];
        nx+=mx[0];
    }
    ny=y+my[1];
    nx=x+mx[1];
    while(input[ny][nx]==c){
        cnt++;
        ny+=my[1];
        nx+=mx[1];
    }
    result=max(result,cnt);

    ny=y+my[2];
    nx=x+mx[2];
    cnt=1;
    while(input[ny][nx]==c){
        cnt++;
        ny+=my[2];
        nx+=mx[2];
    }
    ny=y+my[3];
    nx=x+mx[3];
    while(input[ny][nx]==c){
        cnt++;
        ny+=my[3];
        nx+=mx[3];
    }
    result=max(result,cnt);
}

void dfs(int y, int x){
    find(y,x,input[y][x]);
    if(x+1<=N){
        if(input[y][x]!=input[y][x+1]){
            swap(input[y][x],input[y][x+1]);
            find(y,x,input[y][x]);
            find(y,x+1,input[y][x+1]);
            swap(input[y][x],input[y][x+1]);
        }
        dfs(y,x+1);
    }

    if(y+1<=N){
        if(input[y][x]!=input[y+1][x]){
            swap(input[y][x],input[y+1][x]);
            find(y,x,input[y][x]);
            find(y+1,x,input[y+1][x]);
            swap(input[y][x],input[y+1][x]);
        }
        if(x==1)
            dfs(y+1,x);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(input,'\0',sizeof(input));
    cin>>N;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin>>input[y][x];
        }
    }

    dfs(1,1);
    cout<<result<<'\n';

    return 0;
}
