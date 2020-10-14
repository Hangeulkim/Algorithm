#include<bits/stdc++.h>

using namespace std;

string input;
vector<string> arr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    for(int i=0;i<input.length();i++){
        arr.push_back(input.substr(i));
    }
    sort(arr.begin(),arr.end());
    for(auto it : arr)
        cout<<it<<'\n';

    return 0;
}
