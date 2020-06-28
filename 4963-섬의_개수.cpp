#include<bits/stdc++.h>

using namespace std;

int input[52][52];
int w,h;
int cnt=0;
int my[8]={1,-1,0,0,1,1,-1,-1};
int mx[8]={0,0,1,-1,1,-1,1,-1};

void dfs(int y, int x){
    input[y][x]=0;

    for(int i=0;i<8;i++){
        int ny=y+my[i];
        int nx=x+mx[i];

        if(input[ny][nx]==1)
            dfs(ny,nx);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    do {
        cin>>w>>h;
        if(w==0&&h==0)
            break;
        memset(input,0,sizeof(input));
        cnt=0;

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>input[i][j];
            }
        }

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(input[i][j]==1){
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        cout<<cnt<<'\n';
    } while(true);


    return 0;
}
