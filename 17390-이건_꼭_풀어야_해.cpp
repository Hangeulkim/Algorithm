#include<bits/stdc++.h>

using namespace std;

int N,Q;
int tmp;
int L,R;
int sum[300001];
vector<int> input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>Q;

    input.push_back(0);
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end(),less<int>());

    for(int i=1;i<=N;i++){
        sum[i]=sum[i-1]+input[i];
    }

    while(Q--){
        cin>>L>>R;
        cout<<sum[R]-sum[L-1]<<'\n';
    }


    return 0;
}
