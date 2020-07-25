#include <bits/stdc++.h>
using namespace std;

vector<int> nodes[300001];
int n;
long long Dcount, Gcount;

long long nC3 (long long n) {
        return n * (n - 1) * (n - 2) / 6;
}

int main(void) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
                int a, b;
                scanf("%d %d", &a, &b);

                nodes[a].push_back(b);
                nodes[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
                if (nodes[i].size() >= 2) {
                        for (int j = 0; j < nodes[i].size(); j++) {
                                int node = nodes[i][j];
                                int size = nodes[node].size();
                                if (size > 1) Dcount += (nodes[i].size() - 1) * (size - 1);
                        }
                }
                if (nodes[i].size() >= 3) {
                        Gcount += nC3(nodes[i].size());
                }
        }
        Dcount /= 2;

        if (Dcount > Gcount * 3) printf("D");
        else if (Dcount < Gcount * 3) printf("G");
        else printf("DUDUDUNGA");
}
