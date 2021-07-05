#include<bits/stdc++.h>

using namespace std;

int H,W,X,Y;
int arr[666][666];
int ans[301][301];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>H>>W>>Y>>X;
    for(int i=0;i<H+Y;i++){
        for(int j=0;j<W+X;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=H+Y-1;i>Y-1;i--){
        for(int j=X;j<W+X;j++){
            if(j>=W||i>=H)
                ans[i-Y][j-X]=arr[i][j];
            else
                ans[i-Y][j-X]=arr[i][j]-ans[i][j];
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}