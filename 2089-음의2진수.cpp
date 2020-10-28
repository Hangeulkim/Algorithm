#include<bits/stdc++.h>

using namespace std;

long long int N;
string result="";
int main(){
    cin>>N;

    if(N==0)
        cout<<0<<'\n';
    else{
        while(N){
            if(N%(-2) == 0){
                result+="0";
                N /= -2;
            }
            else{
                result+="1";
                N = (N-1) / -2;
            }
        }
        reverse(result.begin(),result.end());
        cout<<result<<'\n';
    }

    return 0;
}
