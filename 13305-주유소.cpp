#include<bits/stdc++.h>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    vector<int> way(N);
    vector<int> pay(N);

    for(int i=0;i<N-1;i++)
        cin>>way[i];
    for(int i=0;i<N;i++)
        cin>>pay[i];

    long long int sum=0;
    long long int tmp=2100000000;
    for(int i=0;i<N-1;i++){
        if(tmp>pay[i]){
            tmp=pay[i];
        }
        sum+=tmp*way[i];
    }
    cout<<sum<<'\n';

    return 0;
}
