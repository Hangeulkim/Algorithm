#include<bits/stdc++.h>

using namespace std;

int T;
int input[100001][3];
int result[100001][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s,tmp,maxn=-1;
    cin>>T;
    while(T--){
        cin>>s;
        for(int i=1;i<3;i++){
            for(int j=1;j<=s;j++){
                cin>>input[j][i];
                result[j][i]=-1;
            }
        }


        result[1][1]=input[1][1];
        result[1][2]=input[1][2];
        maxn=max(result[1][1],result[1][2]);
        for(int i=2;i<=s;i++){
            result[i][1]=max(max(result[i-2][1],result[i-2][2]),result[i-1][2])+input[i][1];
            result[i][2]=max(max(result[i-2][1],result[i-2][2]),result[i-1][1])+input[i][2];
            maxn=max(maxn,max(result[i][1],result[i][2]));
        }
        cout<<maxn<<'\n';
    }

    return 0;
}
