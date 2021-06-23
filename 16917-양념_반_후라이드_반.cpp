#include<bits/stdc++.h>

using namespace std;

int A,B,C,X,Y;
int ret=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B>>C>>X>>Y;

    int num=min(X,Y);
    ret+=min(C*num*2,A*num+B*num);
    ret+=min(A*(X-num)+B*(Y-num),C*(X+Y-2*num)*2);
    cout<<ret<<'\n';

    return 0;
}