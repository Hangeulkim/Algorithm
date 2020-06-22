#include<iostream>
#include<algorithm>

using namespace std;

int result[10001];
int coinnum[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=0,k=0;
    cin>>n>>k;
    result[0]=1;
    for(int i=1;i<=n;i++){
        cin>>coinnum[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=coinnum[i];j<=k;j++){
            result[j]+=result[j-coinnum[i]];
        }
    }

    cout<<result[k]<<'\n';
    return 0;
}
