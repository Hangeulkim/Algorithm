#include<iostream>
#include<string>

using namespace std;

long long int n;

int jari(){
    int ret=1;
    long long num=1;

    while(num%n){
        ret++;
        num=num*10+1;
        num%=n;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n){
        cout<<jari()<<'\n';
    }

    return 0;
}