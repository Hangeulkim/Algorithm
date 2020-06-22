#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, N[101], M;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> N[i];
    }
    sort(N, N+T);

    return 0;
}
