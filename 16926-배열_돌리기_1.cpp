#include<bits/stdc++.h>

using namespace std;

int N,M,R;
int a[301][301];

void moving(int sy,int sx,int fy,int fx){
    if(fy<sy||fx<sx)
        return ;
    
    int tmp=a[fy][fx];
    for(int i=fx;i>sx;i--)
        a[fy][i]=a[fy][i-1];

    for(int i=fy;i>sy;i--)
        a[i][sx]=a[i-1][sx];

    for(int i=sx;i<fx;i++)
        a[sy][i]=a[sy][i+1];
    
    for(int i=sy;i<fy;i++)
        a[i][fx]=a[i+1][fx];
    a[fy-1][fx]=tmp;


    moving(sy+1,sx+1,fy-1,fx-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<R;i++)
        moving(0,0,N-1,M-1);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}