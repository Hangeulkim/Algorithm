#include<bits/stdc++.h>

using namespace std;

int N;
long long num=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    //9 99 999 9999 99999
    int s=to_string(N).length();
    int k=9;
    int i=1;
    for(i=1;i<s;i++,k*=10){
        N-=k;
        num+=k*i;
    }
    num+=N*i;
    cout<<num;

    return 0;
}
