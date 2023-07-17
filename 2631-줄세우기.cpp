#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[201];
vector<int> dp;

void input(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
}

int bins(int num, int cnt){
    int l=0, r=cnt;

    while(l<=r){
        int mid = (l+r)/2;

        if(dp[mid]>=num)
            r = mid-1;
        else
            l = mid+1;
    }

    return l;
}

void solution(){
    int cnt=0;

    dp.push_back(0);
    for(int i=0;i<N;++i){
        if(arr[i] > dp[cnt]){
            dp.push_back(arr[i]);
            ++cnt;
        }

        else{
            dp[bins(arr[i], cnt)] = arr[i];
        }
    }
    cout<<N-cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}