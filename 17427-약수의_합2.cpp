#include<iostream>
#include<cmath>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    long long int sum=0;
    for(int i=1;i<=N;i++){
        sum+=i*(N/i);
    }

    cout<<sum<<'\n';

    return 0;
}

