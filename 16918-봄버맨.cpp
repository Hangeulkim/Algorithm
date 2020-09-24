#include<bits/stdc++.h>

using namespace std;

char input[222][222][222];
char nbomb[222][222][222];
int R,C,N;
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

void explosion(int cnt){
    memset(input[cnt],'O',sizeof(input[cnt]));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(nbomb[cnt-3][i][j]=='O'){
                input[cnt][i][j]='.';
                for(int d=0;d<4;d++){
                    input[cnt][i+my[d]][j+mx[d]]='.';
                }
            }
        }
    }
}

void new_bomb(int cnt){
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            input[cnt][i][j]='O';
            if(input[cnt-1][i][j]=='.'){
                nbomb[cnt][i][j]='O';
                if(nbomb[cnt-2][i][j]=='O')
                    nbomb[cnt-2][i][j]='.';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(input,'.',sizeof(input));
    memset(nbomb,'.',sizeof(nbomb));
    cin>>R>>C>>N;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>input[0][i][j];
            nbomb[0][i][j]=input[0][i][j];
            input[1][i][j]=input[0][i][j];
        }
    }

    for(int i=2;i<=N;i++){
        if(i%2==1){
            explosion(i);
        }
        else{
            new_bomb(i);
        }
    }

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout<<input[N][i][j];
        }
        cout<<'\n';
    }

    return 0;
}
