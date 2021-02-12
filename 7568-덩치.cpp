#include<bits/stdc++.h>

using namespace std;

int N;
int input[51][2];
int ret;
int result[51];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(result,-1,sizeof(result));
    cin>>N;

    int tmp1,tmp2;
    for (int i = 0; i < N; i++) {
        cin>>tmp1>>tmp2;
        input[i][0]=tmp1;
        input[i][1]=tmp2;
    }

    for(int i=0;i<N;i++){
        int cnt=1;
        for(int j=0;j<N;j++){
            if(i==j)
                continue;
            if(input[i][0]<input[j][0]&&input[i][1]<input[j][1]){
                cnt++;
            }
        }
        result[i]=cnt;
    }

    for (int i = 0; i < N; i++) {
        cout<<result[i]<<" ";
    }

    return 0;
}
