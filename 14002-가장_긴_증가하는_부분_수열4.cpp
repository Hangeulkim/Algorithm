#include<bits/stdc++.h>

using namespace std;

int length;
int N;
int input[1001], idx[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp,maxidx=1,maxn=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>input[i];
        dp[i]=1;
        idx[i]=0;
        for(int j=1;j<i;j++){
            if(input[i]>input[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                idx[i]=j;
            }
        }
        if(maxn<dp[i]){
            maxn=dp[i];
            maxidx=i;
        }
    }
    cout<<maxn<<'\n';

    stack<int> st;
    while(maxidx>0){
        st.push(input[maxidx]);
        maxidx=idx[maxidx];
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
