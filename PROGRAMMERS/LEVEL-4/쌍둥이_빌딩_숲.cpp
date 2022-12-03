#include <string>
#include <vector>

using namespace std;

//���� ���� ������ ������������ ����ٸ�
//100^2 dp�� ����?
//���� ���� / ���� ���� ���̴� ���� ����
// 4 3
// 1 2 4 2
// 1 3 4 4
// 2 3 4 6
long long dp[101][101];
int mod = 1'000'000'007;

int solution(int n, int count) {
    int answer = 0;
    
    dp[n][1]=1;
    for(int i=n-1, idx=2;i>0;--i, ++idx){
        for(int j=idx;j>=1;--j){
            dp[i][j] = (dp[i+1][j] * (idx-1)*2 + dp[i+1][j-1]) % mod;
        }
    }
    
    answer = dp[1][count];
    return answer;
}