#include<bits/stdc++.h>

using namespace std;

int A,B;
int m, tmp;
int result;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B;
    cin>>m;
    while(m--){
        cin>>tmp;
        int k=(int)pow(A,m);
        result+=k*tmp;
    }

    for(int i=B;result!=0;result/=B){
        v.push_back(result%i);
    }

    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }

    return 0;
}
