#include<bits/stdc++.h>

using namespace std;

int N,tmp;
long long int A[1000001],B[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    for(int i=1;i<=N;i++){
        cin>>B[i];
    }
    for(int i=1;i<=N;i++){
        cout<<upper_bound(B+i+1,B+N+1,A[i])-B-i-1<<" ";
    }

    return 0;
}
