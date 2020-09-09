#include<bits/stdc++.h>

using namespace std;

int N;
int input[1000001];
int B,C;
long long int result=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>input[i];
    }
    cin>>B>>C;

    for(int i=1;i<=N;i++){
        result++;
        input[i]-=B;
        if(input[i]>0)
            result+=(long long int)ceil((double)input[i]/C);
    }
    cout<<result<<'\n';

    return 0;
}
