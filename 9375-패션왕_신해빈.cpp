#include<bits/stdc++.h>

using namespace std;

int T,n;
string name,kinds;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        map<string, int> ot;
        while(n--){
            cin>>name>>kinds;
            ot[kinds]++;
        }
        long long ret=1;
        for(auto it : ot){
            ret*=(1+it.second);
        }
        ret--;
        cout<<ret<<'\n';
    }

    return 0;
}