#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
            if(j==0) 
                dp[i][0]=dp[i-1][0]+triangle[i][0];
            else if(j==i)
                dp[i][i]=dp[i-1][i-1]+triangle[i][i];
            else
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
        }
    }
    
    
    answer = *max_element(dp[triangle.size()-1],dp[triangle.size()-1]+501);
    
    return answer;
}