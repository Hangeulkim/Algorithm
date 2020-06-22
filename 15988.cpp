#include<iostream>
#include<vector>
using namespace std;
vector<long long int> result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    result.push_back(0);
    result.push_back(1);
    result.push_back(2);
    result.push_back(4);
    for(int i=4;i<=1000000;i++){
        result.push_back((result[i-3]+result[i-2]+result[i-1])%1000000009);
    }
    long long int testcase=0;
    cin>>testcase;
    while(testcase--){
        int input=0;
        cin>>input;
        cout<<result[input]<<'\n';
    }
    return 0;
}
