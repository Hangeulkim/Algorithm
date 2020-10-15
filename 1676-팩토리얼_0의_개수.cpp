#include<bits/stdc++.h>

using namespace std;

int N,cnt2=0,cnt5=0;

void num2(int i){
    while(i%2==0){
        cnt2++;
        i/=2;
    }
}

void num5(int i){
    while(i%5==0){
        cnt5++;
        i/=5;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=2;i<=N;i++){
        num2(i);
        num5(i);
    }
    cout<<min(cnt2,cnt5);

    return 0;
}
