#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][2];

int solution(vector<int> citations) {
    int answer = 0, cnt=0;
    int sz = citations.size();

    
    sort(citations.begin(),citations.end());
    
    for(auto it : citations){
        if(it==0)
            dp[0][0]++;
        dp[0][1]++;
    }
    
    for(int i=1;i<1001;i++){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        while(cnt<sz&&citations[cnt]<i){
            dp[i][0]++;
            dp[i][1]--;
            cnt++;
        }
        if(dp[i][0]<=i&&dp[i][1]>=i){
            answer=i;
        }
    }
    
    return answer;
}