#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long fibo[46]={0,1};
    int testcase=0;
    cin>>testcase;
    for(int i=2;i<=testcase;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    cout<<fibo[testcase]<<'\n';


    return 0;
}
