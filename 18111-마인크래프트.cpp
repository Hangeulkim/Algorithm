#include<bits/stdc++.h>

using namespace std;

int N,M,B;
int input[501][501];
int rett=987654321,reth=-1;
int minh=987654321,maxh=-1;

int minecraft(int h){
    int t=0;
    int tmpB=B;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int need=abs(h-input[i][j]);
            if(input[i][j]<h){
                tmpB-=need;
                t+=need;
            }
            else if(input[i][j]>h){
                tmpB+=need;
                t+=need*2;
            }
        }
    }

    if(tmpB<0) return -1;
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>B;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>input[i][j];
            minh=min(minh,input[i][j]);
            maxh=max(maxh,input[i][j]);
        }
    }

    for(int i=minh;i<=maxh;i++){
        int curt=minecraft(i);

        if(curt<0) continue;
        if(rett>=curt){
            rett=curt;
            reth=i;
        }
    }
    cout<<rett<<" "<<reth;


    return 0;
}
