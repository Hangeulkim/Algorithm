#include<bits/stdc++.h>

using namespace std;

int L;
string input;
long long int r=31,M=1234567891;
long long int ret;
long long sum=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>L>>input;
    for(int i=0;i<L;i++){
        ret=(ret+(input[i]-'a'+1)*sum)%M;
        sum=(sum*r)%M;
    }
    cout<<ret;

    return 0;
}
