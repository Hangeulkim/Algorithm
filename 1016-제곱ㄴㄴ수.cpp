#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

ll num1,num2;
ll cnt=0;
bool check[1000001]={false,},isprime[1000001]={false,};

void result(){
    ll max_num = (ll)sqrt(num2);

    for(ll i=2;i<=max_num;i++){
        ll tmp = i*i;
        ll start=tmp*(num1/tmp);
        for(ll j=start;j<=num2;j+=tmp){
            if(j>=num1) check[j-num1]=true;
        }
    }

    for(int i=0;i<=num2-num1;i++){
        if(!check[i]){
            cnt++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>num1>>num2;

    result();
    cout<<cnt<<'\n';

    return 0;
}
