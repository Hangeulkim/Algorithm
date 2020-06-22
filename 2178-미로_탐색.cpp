#include<bits/stdc++.h>

using namespace std;

char input[101][101];
int check[101][101];
int N,M;
queue<pair<int,int> > go;

void find(int y,int x){
    if((y+1)<N&&input[y+1][x]=='1'){
        input[y+1][x]=0;
        check[y+1][x]=check[y][x]+1;
        go.push(make_pair(y+1,x));
    }

    if((y-1)>=0&&input[y-1][x]=='1'){
        input[y-1][x]=0;
        check[y-1][x]=check[y][x]+1;
        go.push(make_pair(y-1,x));
    }

    if((x+1)<M&&input[y][x+1]=='1'){
        input[y][x+1]=0;
        check[y][x+1]=check[y][x]+1;
        go.push(make_pair(y,x+1));
    }

    if((x-1)>=0&&input[y][x-1]=='1'){
        input[y][x-1]=0;
        check[y][x-1]=check[y][x]+1;
        go.push(make_pair(y,x-1));
    }

    if(input[y][x]==1){
        input[y][x]=0;
    }


    go.pop();
    if(go.empty()) return;

    find(go.front().first,go.front().second);
}


int main(){
    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++){
        scanf(" %s",input[i]);
    }

    go.push(make_pair(0,0));
    find(0,0);
    printf("%d\n",check[N-1][M-1]+1);

    return 0;
}
