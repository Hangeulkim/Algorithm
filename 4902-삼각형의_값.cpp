#include<bits/stdc++.h>

using namespace std;

int N;
int ans,tmp;
int ps[402][802];
int T=1;

void find(int y, int l, int r, int sum){
    if(y>N||y<1||l<1||r>(y*2)-1){
        return ;
    }

    sum+=ps[y][r]-ps[y][l-1];
    ans=max(ans,sum);

    if(l%2==1){
        find(y+1,l,r+2,sum);
    }

    else{
        find(y-1,l-2,r,sum);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    do {
        memset(ps,0,sizeof(ps));
        cin>>N;
        if(N==0)
            break;

        ans=-987654321;
        for(int y=1;y<=N;y++){
            for(int x=1;x<=(y*2)-1;x++){
                cin>>tmp;
                ps[y][x]=ps[y][x-1]+tmp;
            }
        }

        for(int y=1;y<=N;y++){
            for(int x=1;x<=(y*2)-1;x++){
                find(y,x,x,0);
            }
        }

        printf("%d. %d\n",T++,ans);
    } while(1);



    return 0;
}
