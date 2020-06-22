#include<iostream>

using namespace std;
long long fibo[1500000]={0,1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    long long testcase=0;
    cin>>testcase;
    long long mod=1000000;
    testcase%=1500000;
    for(int i=2;i<=(int)testcase;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%mod;
    }
    cout<<fibo[testcase]<<'\n';


    return 0;
}
