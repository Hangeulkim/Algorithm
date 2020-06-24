#include<bits/stdc++.h>

using namespace std;

vector<int> input;

long long gcd(int tmp1,int tmp2){
    int tmp=0;
    if(tmp2>tmp1){
        tmp=tmp1;
        tmp1=tmp2;
        tmp2=tmp;
    }
    while(tmp1%tmp2!=0){
        tmp=tmp2;
        tmp2=tmp1%tmp2;
        tmp1=tmp;
    }
    return tmp2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T,N,tmp;
    cin>>T;
    while(T--){
        input.clear();
        cin>>N;
        long long sum=0;
        for(int i=0;i<N;i++){
            cin>>tmp;
            input.push_back(tmp);
        }
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                sum+=gcd(input[i],input[j]);
            }
        }
        cout<<sum<<'\n';
    }

    return 0;
}
