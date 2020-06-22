#include<bits/stdc++.h>

using namespace std;

int N,M,tmp;
vector<int> input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end(),greater<int>());

    int result=0;
    int top=input[0];
    int btm=0;
    int mid=0;

    while(btm<top){
        long long sum=0;
        mid = (top+btm)/2;
        for(int i=0;i<N&&input[i]-mid>0;i++)
            sum+=input[i]-mid;
        if(sum < M){
            top = mid;
        }
        else{
            result = mid;
            btm=mid+1;
        }
    }

    cout<<result;
    return 0;
}
