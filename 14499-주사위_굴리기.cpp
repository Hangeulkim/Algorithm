#include<bits/stdc++.h>

using namespace std;

int N,M,x,y,K,m;
int mv[5][2]={{0,0},
            {1,0},
            {-1,0},
            {0,-1},
            {0,1}};

int input[21][21];
int dice[5][5];

void move1(){
    int tmp_dice[5][5];

    tmp_dice[1][2]=dice[1][2];
    tmp_dice[2][1]=dice[4][2];
    tmp_dice[2][2]=dice[2][1];
    tmp_dice[2][3]=dice[2][2];
    tmp_dice[3][2]=dice[3][2];
    if(input[y][x]==0){
        input[y][x]=dice[2][3];
        tmp_dice[4][2]=dice[2][3];
    }
    else{
        tmp_dice[4][2]=input[y][x];
        input[y][x]=0;
    }

    dice[1][2]=tmp_dice[1][2];
    dice[2][1]=tmp_dice[2][1];
    dice[2][2]=tmp_dice[2][2];
    dice[2][3]=tmp_dice[2][3];
    dice[3][2]=tmp_dice[3][2];
    dice[4][2]=tmp_dice[4][2];
}

void move2(){
    int tmp_dice[5][5];

    tmp_dice[1][2]=dice[1][2];
    tmp_dice[2][1]=dice[2][2];
    tmp_dice[2][2]=dice[2][3];
    tmp_dice[2][3]=dice[4][2];
    tmp_dice[3][2]=dice[3][2];
    if(input[y][x]==0){
        input[y][x]=dice[2][1];
        tmp_dice[4][2]=dice[2][1];
    }
    else{
        tmp_dice[4][2]=input[y][x];
        input[y][x]=0;
    }

    dice[1][2]=tmp_dice[1][2];
    dice[2][1]=tmp_dice[2][1];
    dice[2][2]=tmp_dice[2][2];
    dice[2][3]=tmp_dice[2][3];
    dice[3][2]=tmp_dice[3][2];
    dice[4][2]=tmp_dice[4][2];
}

void move3(){
    int tmp_dice[5][5];

    tmp_dice[1][2]=dice[2][2];
    tmp_dice[2][1]=dice[2][1];
    tmp_dice[2][2]=dice[3][2];
    tmp_dice[2][3]=dice[2][3];
    tmp_dice[3][2]=dice[4][2];
    if(input[y][x]==0){
        input[y][x]=dice[1][2];
        tmp_dice[4][2]=dice[1][2];
    }
    else{
        tmp_dice[4][2]=input[y][x];
        input[y][x]=0;
    }

    dice[1][2]=tmp_dice[1][2];
    dice[2][1]=tmp_dice[2][1];
    dice[2][2]=tmp_dice[2][2];
    dice[2][3]=tmp_dice[2][3];
    dice[3][2]=tmp_dice[3][2];
    dice[4][2]=tmp_dice[4][2];
}

void move4(){
    int tmp_dice[5][5];

    tmp_dice[1][2]=dice[4][2];
    tmp_dice[2][1]=dice[2][1];
    tmp_dice[2][2]=dice[1][2];
    tmp_dice[2][3]=dice[2][3];
    tmp_dice[3][2]=dice[2][2];
    if(input[y][x]==0){
        input[y][x]=dice[3][2];
        tmp_dice[4][2]=dice[3][2];
    }
    else{
        tmp_dice[4][2]=input[y][x];
        input[y][x]=0;
    }

    dice[1][2]=tmp_dice[1][2];
    dice[2][1]=tmp_dice[2][1];
    dice[2][2]=tmp_dice[2][2];
    dice[2][3]=tmp_dice[2][3];
    dice[3][2]=tmp_dice[3][2];
    dice[4][2]=tmp_dice[4][2];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>y>>x>>K;

    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            cin>>input[y][x];
        }
    }

    while(K--){
        cin>>m;
        int ny=y+mv[m][1];
        int nx=x+mv[m][0];

        if(ny<0||ny>=N||nx<0||nx>=M)
            continue;

        y=ny;
        x=nx;
        switch (m) {
            case 1:
                move1();
                break;
            case 2:
                move2();
                break;
            case 3:
                move3();
                break;
            case 4:
                move4();
                break;
        }
        cout<<dice[2][2]<<'\n';
    }

    return 0;
}
