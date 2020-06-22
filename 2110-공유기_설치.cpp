#include<bits/stdc++.h>

using namespace std;
int N,C;
long long int btm=1,top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>C;
    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin>>input[i];
    }

    sort(input.begin(),input.end());

    top=input[N-1]-input[0];
    int result;
    while(btm<=top){
        long long int mid=(top+btm)/2;
        int cnt=1;
        int tmp=input[0];

        for(int i=1;i<N;i++){
            int d=input[i]-tmp;
            if(mid<=d){
                cnt++;
                tmp=input[i];
            }

        }

        if(cnt>=C){
            btm=mid+1;
            result=mid;
        }
        else
            top=mid-1;
    }
    cout<<result<<'\n';

    return 0;
}
