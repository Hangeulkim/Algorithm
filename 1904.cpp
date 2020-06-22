#include<iostream>
#include<vector>
using namespace std;
vector<int> result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    result.push_back(0);
    result.push_back(1);
    result.push_back(2);
    int input=0;
    cin>>input;
    for(int i=3;i<=input;i++){
        result.push_back((result[i-2]+result[i-1])%15746);
    }
    cout<<result[input]<<'\n';

    return 0;
}
