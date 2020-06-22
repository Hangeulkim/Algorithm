#include<bits/stdc++.h>

using namespace std;
vector<int> a;
vector<int> b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase,tmp;
    cin>>testcase;

    for(int i=0;i<testcase;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<testcase;i++){
        cin>>tmp;
        b.push_back(tmp);
    }

    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end());
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i]*b[i];
    }
    cout<<sum<<'\n';

    return 0;
}
