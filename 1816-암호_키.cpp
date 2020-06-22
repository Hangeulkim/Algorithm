#include<bits/stdc++.h>

using namespace std;

long long int S;

bool chk[1000001];
int N;

void eratos(){
    chk[1]=true;
    for(int i=2;i<1000001;i++){
        if(!chk[i]){
            for(int j=2;j*i<1000001;j++){
                chk[i*j]=true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    eratos();

    cin>>N;
    while(N--){
        cin>>S;

        bool eflag=false;

        for(int i=2;i<1000001;i++){
            if(chk[i])
                continue;
            else{
                if(S%i==0){
                    eflag=true;
                    break;
                }
            }
        }
        if(eflag){
            cout<<"NO"<<'\n';
        }
        else
            cout<<"YES"<<'\n';
    }

    return 0;
}
