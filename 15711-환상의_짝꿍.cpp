#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int T=0;
vector<int> sosu;
bool prime[2000001]={false,};

void aritos(){
    for(int i=2;i<2000001;i++){
        if(!prime[i]){
            sosu.push_back(i);
            for(int j=2;i*j<2000001;j++){
                prime[i*j]=true;
            }
        }
    }
}

bool isPrime(ull num){
    for(int i=0;i<sosu.size()&&(ull)sosu[i]*sosu[i]<=num;i++){
        if(num%sosu[i]==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    aritos();

    cin>>T;
    ull a,b,sum;
    while(T--){
        cin>>a>>b;
        sum=a+b;

        if(sum<4){
            cout<<"NO"<<'\n';
            continue;
        }
        if(sum%2==0){
            cout<<"YES"<<'\n';
            continue;
        }

        if(isPrime(sum-2)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}
