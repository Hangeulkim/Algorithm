#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>

using namespace std;

int age;
string input;
vector<pair<pair<int, int>, string> > result;
bool comp(pair<pair<int, int>, string> a,pair<pair<int, int>, string> b){
    if(a.first.first==b.first.first) return a.first.second<b.first.second;
    return a.first.first<b.first.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>age>>input;
        result.push_back(make_pair(make_pair(age,i),input));
    }

    sort(result.begin(),result.end(),comp);

    int leng=result.size();
    for(auto it : result) cout<<it.first.first<<" "<<it.second<<'\n';

    return 0;
}
