#include<bits/stdc++.h>

using namespace std;

int length;
int N;
int input[1001], dpf[1001], dpb[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int maxn=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>input[i];
        dpf[i]=1;
        dpb[i]=1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(input[i]>input[j]&&dpf[i]<dpf[j]+1){
                dpf[i]=dpf[j]+1;
            }
        }
    }
    for(int i=N;i>=1;i--){
        for(int j=N;j>i;j--){
            if(input[i]>input[j]&&dpb[i]<dpb[j]+1){
                dpb[i]=dpb[j]+1;
            }
        }
    }
    for(int i=1;i<=N;i++){
        maxn=max(maxn,dpf[i]+dpb[i]-1);
    }
    cout<<maxn<<'\n';

    return 0;
}
