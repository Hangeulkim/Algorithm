#include<bits/stdc++.h>

using namespace std;

int input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;

    for(int i=1;i<=input;i++){
        int sum=i,tmp=i;
        while(tmp>0){
            sum+=tmp%10;
            tmp/=10;
        }
        if(sum==input){
            cout<<i;
            return 0;
        }
    }
    cout<<0;

    return 0;
}
