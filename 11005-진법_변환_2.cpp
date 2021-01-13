#include<bits/stdc++.h>

using namespace std;

int N,B;
vector<int> zin;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>B;
    while(N>0){
        zin.push_back(N%B);
        N/=B;
    }
    for(int i=zin.size()-1;i>=0;i--){
        if(zin[i]>9)
            cout<<(char)('A'+zin[i]-10);
        else
            cout<<zin[i];
    }

    return 0;
}
