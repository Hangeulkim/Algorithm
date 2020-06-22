#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> input;
vector<int> num;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0,M=0,tmp=0;
    cin>>N;
    while(N--){
        cin>>tmp;
        input.push_back(tmp);
    }
    cin>>M;
    sort(input.begin(),input.end());
    auto st=unique(input.begin(),input.end());
    input.erase(st,input.end());
    while(M--){
        cin>>tmp;
        if(binary_search(input.begin(),input.end(),tmp)) cout<<"1"<<'\n';
        else cout<<"0"<<'\n';
    }


    return 0;
}
