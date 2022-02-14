#include <bits/stdc++.h>

using namespace std;

long long mod = 1'000'000'000;
int dp[101][10][1 << 10];
int N;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int all = (1 << 10) - 1;

    for (int i = 1; i < 10; i++)
        dp[1][i][1 << i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < all; k++)
            {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
                else
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++)
        ans = (ans + dp[N][i][all]) % mod;

    cout << ans;

    return 0;
}