#include<iostream>
#include<vector>

using namespace std;
vector<long long int> result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0;
    cin>>testcase;
    result.push_back(0);
    result.push_back(1);
    result.push_back(1);
    result.push_back(1);
    result.push_back(2);
    result.push_back(2);
    for(int i=6;i<=100;i++){
        result.push_back(result[i-5]+result[i-1]);
    }
    while(testcase--){
        int input=0;
        cin>>input;
        cout<<result[input]<<'\n';
    }

    return 0;
}
