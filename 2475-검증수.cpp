#include<bits/stdc++.h>

using namespace std;

int sum=0;
int input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d=5;
    while(d--){
        cin>>input;
        sum+=input*input;
    }
    cout<<sum%10;

    return 0;
}
