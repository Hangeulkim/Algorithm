#include<bits/stdc++.h>

using namespace std;

bool check[10001];
int sum[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(check,true,sizeof(check));
    check[1]=false;

    memset(sum,0,sizeof(sum));
    int prev=1;
    int minnum=0,maxnum=0;

    for(int i=2;i<=10000;i++){
        if(check[i]){
            sum[i]=sum[prev]+i;
            prev=i;
            for(int j=2;i*j<10001;j++){
                check[i*j]=false;
            }
        }
    }

    int a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++){
        if(check[i]){
            minnum=i;
            break;
        }
    }
    for(int i=b;i>=a;i--){
        if(check[i]){
            maxnum=i;
            break;
        }
    }

    if(minnum==0) cout<<"-1"<<'\n';

    else{
        if(minnum==maxnum){
            cout<<minnum<<'\n';
        }
        else cout<<sum[maxnum]-sum[minnum]+minnum<<'\n';


        cout<<minnum<<'\n';
    }

    return 0;
}
