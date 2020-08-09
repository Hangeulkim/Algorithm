#include<bits/stdc++.h>

using namespace std;

int C,P;
int input[101];
int block[8][4][5]={
    {},
    {
        {0,-1,-1,-1,-1},
        {0,0,0,0,-1},
        {0,-1,-1,-1,-1},
        {0,0,0,0,-1}
    },
    {
        {0,0,-1,-1,-1},
        {0,0,-1,-1,-1},
        {0,0,-1,-1,-1},
        {0,0,-1,-1,-1}
    },
    {
        {0,0,1,-1,-1},
        {1,0,-1,-1,-1},
        {0,0,1,-1,-1},
        {1,0,-1,-1,-1}
    },
    {
        {1,0,0,-1,-1},
        {0,1,-1,-1,-1},
        {1,0,0,-1,-1},
        {0,1,-1,-1,-1}
    },
    {
        {0,0,0,-1,-1},
        {1,0,-1,-1,-1},
        {1,0,1,-1,-1},
        {0,1,-1,-1,-1}
    },
    {
        {0,0,0,-1,-1},
        {0,0,-1,-1,-1},
        {0,1,1,-1,-1},
        {2,0,-1,-1,-1}
    },
    {
        {0,0,0,-1,-1},
        {0,2,-1,-1,-1},
        {1,1,0,-1,-1},
        {0,0,-1,-1,-1}
    },
};
int cnt=0;
int s=0;

void chk(int x){
    for(int i=0;i<s;i++){
        int num=1;
        cnt++;
        while(block[P][i][num]!=-1){
            int gapb=block[P][i][num-1]-block[P][i][num];
            int gap=input[x+num-1]-input[x+num];

            if(gap!=gapb||x+num>C){
                cnt--;
                break;
            }

            num++;
        }
    }
}

void dfs(int x){
    if(x>C)
        return;

    chk(x);
    dfs(x+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>C>>P;

    for(int i=1;i<=C;i++){
        cin>>input[i];
    }

    switch (P) {
        case 1:
        s=2;
        break;
        case 2:
        s=1;
        break;
        case 3:
        s=2;
        break;
        case 4:
        s=2;
        break;
        case 5:
        s=4;
        break;
        case 6:
        s=4;
        break;
        case 7:
        s=4;
        break;
    }

    dfs(1);
    cout<<cnt<<'\n';

    return 0;
}
