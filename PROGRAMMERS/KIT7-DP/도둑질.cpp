#include <string>
#include <vector>

using namespace std;
int dp[2][1000001];

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    
    dp[0][0]=money[0];
    dp[0][1]=money[0];
    dp[1][1]=money[1];
    for(int i=2;i<n-1;i++){
        dp[0][i]=max(dp[0][i-2]+money[i],dp[0][i-1]);
    }
    for(int i=2;i<n;i++){
        dp[1][i]=max(dp[1][i-2]+money[i],dp[1][i-1]);
    }
    
    answer=max(dp[0][n-2],dp[1][n-1]);
    return answer;
}