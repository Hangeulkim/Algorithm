#include<iostream>

using namespace std;

int N,K;
string arr;
void input(){
    cin>>N>>K>>arr;
}

void solution(){
    int cnt=0;
    for(int i=0;i<N;++i){
        if(arr[i]=='P'){
            for(int j=max(0,i-K);j<=min(i+K,N-1);++j){
                if(arr[j]=='H'){
                    ++cnt;
                    arr[j]='X';
                    break;
                }
            }
        }
    }
    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}