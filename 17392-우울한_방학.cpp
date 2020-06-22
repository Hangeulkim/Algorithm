#include<bits/stdc++.h>

using namespace std;

int M,N,tmp,H;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        H+=tmp+1;
    }

    M-=H;

    if(M<=0) cout<<0<<'\n';
    else{
        int result=0;
        int tmp=M/(N+1),nam=M%(N+1);


        result=tmp*(2*tmp+1)*(tmp+1)/6*(N+1-nam)+(tmp+1)*(2*(tmp+1)+1)*(tmp+1+1)/6*(nam);


        cout<<result<<'\n';
    }

    return 0;
}
