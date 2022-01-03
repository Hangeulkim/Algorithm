#include<bits/stdc++.h>

using namespace std;

int N,M;
long long arr[1025][1025];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    long long tmp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>tmp;
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+tmp;
        }
    }
    int x1,x2,y1,y2;
    while(M--){
        cin>>y1>>x1>>y2>>x2;
        cout<<arr[y2][x2]-arr[y2][x1-1]-arr[y1-1][x2]+arr[y1-1][x1-1]<<'\n';
    }

    return 0;
}