#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int N, T;
long long int gn[1000001];
long long int fn[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for(int i=1;i<=1000000;i++){
        for(int j=1;i*j<1000001;j++){
            fn[i*j]+=i;
        }
    }

    for(int i=1;i<=1000000;i++){
        gn[i]=gn[i-1]+fn[i];
    }


    while(T--){
        cin>>N;
        cout<<gn[N]<<'\n';
    }

    return 0;
}

