#include<bits/stdc++.h>

using namespace std;

int N;
int input[11][11];
vector<int> arr;

int val(){
    int result=0;
    for(int i=0;i<N-1;i++){
        if(input[arr[i]][arr[i+1]]==0)
            return 987654321;
        result+=input[arr[i]][arr[i+1]];
    }
    if(input[arr[N-1]][arr[0]]==0)
        return 987654321;
    result+=input[arr[N-1]][arr[0]];
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int result=987654321;

    memset(input,0,sizeof(input));
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
        }
        arr.push_back(i);
    }

    do {
        result=min(result,val());
    } while(next_permutation(arr.begin(),arr.end()));
    cout<<result<<'\n';

    return 0;
}
