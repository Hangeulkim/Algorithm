#include<iostream>
#include<algorithm>
using namespace std;

int n[100];

int gcd(int a, int b){
    if(a<b){
        int tmp=0;
        tmp=a;
        a=b;
        b=tmp;
    }
    int mod=a%b;
    while(mod!=0){
        a=b;
        b=mod;
        mod=a%b;
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cas=0;
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>n[i];
    }
    for(int i=1;i<cas;i++){
        int tmp=gcd(n[0],n[i]);
        cout<<n[0]/tmp<<"/"<<n[i]/tmp<<"\n";
        }


    return 0;
}
