#include<bits/stdc++.h>

using namespace std;

int maxnum=-987654321,minnum=987654321,input;
int ret=0;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    while(N--){
        cin>>input;
        if (input<minnum) {
            minnum=input;
        }
        if (input>maxnum) {
            maxnum=input;
        }
    }
    cout<<minnum<<" "<<maxnum;

    return 0;
}
