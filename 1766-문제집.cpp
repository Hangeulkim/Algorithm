#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> prob[32001];
int num[32001];
int a, b;

void topology()
{
    priority_queue<int> pq;

    for (int i = 1; i <= N; i++)
    {
        if (!num[i])
            pq.push(-i);
    }

    while (!pq.empty())
    {
        int now = -pq.top();
        pq.pop();

        cout << now << " ";

        for (auto it : prob[now])
        {
            num[it]--;
            
            if (!num[it])
                pq.push(-it);
        }
        
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        prob[a].push_back(b);
        num[b]++;
    }

    topology();

    return 0;
}