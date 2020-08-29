#include<bits/stdc++.h>

using namespace std;

int N;
int scv[3];
int dp[61][61][61];

int find(int a, int b, int c){
    if(a<=0&&b<=0&&c<=0) return 0;

    a=a<0?0:a;
    b=b<0?0:b;
    c=c<0?0:c;
    int &ret=dp[a][b][c];
    if(ret!=-1) return ret;
    int arr[3]={1,3,9};

    ret=987654321;
    do{
        ret=min(ret,find(a-arr[0],b-arr[1],c-arr[2])+1);
    }while(next_permutation(arr,arr+3));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(scv,0,sizeof(scv));
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>scv[i];

    memset(dp,-1,sizeof(dp));
    cout<<find(scv[0],scv[1],scv[2]);

    return 0;
}
