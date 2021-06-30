#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    int K=N*M;

    for(int i=0;i<N;i++){
        int num=arr[i][0];
        for(int j=1;j<M;j++){
            if(arr[i][j]>arr[i][j-1])
                num+=arr[i][j]-arr[i][j-1];
        }
        K+=num;
    }

    for(int j=0;j<M;j++){
        int num=arr[0][j];
        for(int i=1;i<N;i++){
            if(arr[i][j]>arr[i-1][j])
                num+=arr[i][j]-arr[i-1][j];
        }
        K+=num;
    }

    cout<<K*2;

    return 0;
}