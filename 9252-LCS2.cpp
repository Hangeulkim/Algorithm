#include<bits/stdc++.h>

using namespace std;

string a,b;
int dp[1001][1001];
stack<char> result;

void find(){
    int lengA=a.length();
    int lengB=b.length();
    int cnt=0;

    for(int i=0;i<lengA;i++){
        for(int j=0;j<lengB;j++){
            if(a[i]==b[j])
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }

    cnt=dp[lengA][lengB];
    cout<<cnt<<'\n';

    while(dp[lengA][lengB]!=0){
        if(dp[lengA][lengB]==dp[lengA-1][lengB])
            lengA--;
        else if(dp[lengA][lengB]==dp[lengA][lengB-1])
            lengB--;
        else{
            result.push(a[lengA-1]);
            lengA--;
            lengB--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    find();
    while(!result.empty()){
        cout<<result.top();
        result.pop();
    }
    cout<<'\n';
    return 0;
}
