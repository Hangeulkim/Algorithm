#include<bits/stdc++.h>

using namespace std;

int topny[1001][10];
int K,T;
bool visit[1001];

void move(int what, int where){
    int tmp;
    if(where==1){
        tmp=topny[what][7];
        for(int i=7;i>0;i--){
            topny[what][i]=topny[what][i-1];
        }
        topny[what][0]=tmp;
    }
    else if(where==-1){
        tmp=topny[what][0];
        for(int i=0;i<7;i++){
            topny[what][i]=topny[what][i+1];
        }
        topny[what][7]=tmp;
    }
}

void find(int what, int where){
    visit[what]=true;

    if(what+1<=T&&!visit[what+1]&&topny[what][2]!=topny[what+1][6]){
        find(what+1,where==1?-1:1);
    }
    if(what-1>0&&!visit[what-1]&&topny[what][6]!=topny[what-1][2]){
        find(what-1,where==1?-1:1);
    }
    move(what,where);
}


int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        for(int j=0;j<8;j++){
            scanf("%1d",&topny[i][j]);
        }
    }
    scanf("%d",&K);
    while(K--){
        memset(visit,false,sizeof(visit));
        int what,where;
        scanf("%d %d",&what,&where);
        find(what,where);
    }
    int sum=0;
    for(int i=1;i<=T;i++){
        if(topny[i][0]==1){
            sum++;
        }
    }
    printf("%d\n",sum);

    return 0;
}
