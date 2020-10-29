#include<bits/stdc++.h>

using namespace std;

int T,N;
bool sosu[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(sosu,true,sizeof(sosu));
    sosu[1]=false;
    for(int i=2;i<1000001;i++){
        if(sosu[i]){
            for(int j=2;i*j<1000001;j++){
                sosu[i*j]=false;
            }
        }
    }


    cin>>T;
    while(T--){
        int cnt=0;
        cin>>N;

        if(N==4)
            cnt++;
        for(int i=3;i<=N/2;i+=2){
            if(sosu[i]&&sosu[N-i])
                cnt++;
        }

        cout<<cnt<<'\n';
    }

    return 0;
}
