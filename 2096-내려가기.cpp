#include<bits/stdc++.h>

using namespace std;

int N;
int arr[3];
int mina[3],maxa[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[0]>>arr[1]>>arr[2];

        mina[0]=min(mina[0],mina[1]);
        mina[2]=min(mina[1],mina[2]);
        mina[1]=min(mina[0],mina[2]);
        mina[0]+=arr[0];
        mina[1]+=arr[1];
        mina[2]+=arr[2];

        maxa[0]=max(maxa[0],maxa[1]);
        maxa[2]=max(maxa[1],maxa[2]);
        maxa[1]=max(maxa[2],maxa[0]);
        maxa[0]+=arr[0];
        maxa[1]+=arr[1];
        maxa[2]+=arr[2];
    }
    cout<<max(max(maxa[0],maxa[1]),maxa[2])<<" "<<min(min(mina[0],mina[1]),mina[2]);

    return 0;
}