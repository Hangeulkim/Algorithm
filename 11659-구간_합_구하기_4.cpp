#include<bits/stdc++.h>

using namespace std;

int start,endnum;
long long ps[100001];
int N,M;
int input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;

    for(int i=1;i<=N;i++){
        cin>>input;
        ps[i]=ps[i-1]+input;
    }

    while(M--){
        cin>>start>>endnum;
        if(start>endnum)
            swap(start,endnum);

        cout<<ps[endnum]-ps[start-1]<<'\n';
    }
}
