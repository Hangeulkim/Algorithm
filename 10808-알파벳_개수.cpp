#include<bits/stdc++.h>

using namespace std;

int cnt[301];
string input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    for(int i=0;i<input.length();i++){
        cnt[input[i]]++;
    }
    for(int i='a';i<='z';i++)
        cout<<cnt[i]<<" ";

    return 0;
}
