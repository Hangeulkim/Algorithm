#include<iostream>
#include<algorithm>
#include<vector>

bool desc(int a,int b){
    return a>b;
}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> result;
    int testcase=0;
    int tmp=0;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>tmp;
        result.push_back(tmp);
    }
    sort(result.begin(),result.end(),desc);
    for(int i=0;i<testcase;i++) cout<<result[i]<<'\n';


    return 0;
}
