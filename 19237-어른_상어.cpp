#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m[4][2] = {
    {-1, 0},
    {1, 0},
    {-1, 0},
    {1, 0}};

int sangm[401][4][4];
int sangdat[401];
int arr[21][21][2];
int N, M, K;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j][0];
            arr[i][j][1] = K;
        }
    }

    for (int i = 1; i <= M; i++)
        cin >> sangdat[i];

    vector<vector<int>> tmp(4, vector<int>(2, 0));
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> tmp[0][0] >> tmp[1][0] >> tmp[2][0] >> tmp[3][0];
            tmp[0][1] = 0;
            tmp[1][1] = 1;
            tmp[2][1] = 2;
            tmp[3][1] = 3;

            sort(tmp.begin(), tmp.end());
            sangm[i][j][0] = tmp[0][1];
            sangm[i][j][1] = tmp[1][1];
            sangm[i][j][2] = tmp[2][1];
            sangm[i][j][3] = tmp[3][1];
        }
    }

    dfs(1);

    return 0;
}