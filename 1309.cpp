#include<iostream>
#include<vector>
using namespace std;
vector<int> result[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int input=0;
    cin>>input;
    int answer=0;
    result[0].push_back(1);
    result[1].push_back(0);
    result[2].push_back(0);
    for(int i=1;i<=input;i++){
        result[0].push_back((result[0][i-1]+result[1][i-1]+result[2][i-1])%9901);
        result[1].push_back((result[0][i-1]+result[2][i-1])%9901);
        result[2].push_back((result[0][i-1]+result[2][i-1])%9901);
    }
    answer=(result[0].back()+result[1].back()+result[2].back())%9901;
    cout<<answer<<'\n';
    return 0;
}
