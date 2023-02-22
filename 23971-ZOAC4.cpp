#include<iostream>
#include<cmath>

using namespace std;

int H,W,N,M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>H>>W>>N>>M;

    cout<<(int)ceil((double)H/(N+1)) * (int)ceil((double)W/(M+1))<<'\n';

    return 0;
}