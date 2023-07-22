#include<iostream>

using namespace std;

int N, A, B;

void input(){
    cin>>N>>A>>B;
}

void solution(){
    if(A + B - 1 > N){
        cout<<-1<<'\n';
        return;
    }

    if(A==1&&B!=1)
        cout<<B<<" ";

    for(int i=0;i<N-A-B+1;++i){
        cout<<1<<" ";
    }

    if(A>=B){
        for(int i=1;i<=A;++i){
            cout<<i<<" ";
        }
        for(int i=B-1;i>0;--i){
            cout<<i<<" ";
        }
    }
    else{
        for(int i=1;i<A;++i){
            cout<<i<<" ";
        }
        for(int i = A==1 && B!=1 ? B-1 : B;i>0;--i){
            cout<<i<<" ";
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}