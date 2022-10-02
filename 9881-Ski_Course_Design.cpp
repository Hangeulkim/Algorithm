#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> hills;

void Input(){
    cin>>N;
    
    hills.resize(N);
    for(int i=0;i<N;i++)
        cin>>hills[i];
    sort(hills.begin(),hills.end());
}

int calc(){
    int ret=987654321;

    for(int r=hills[N-1], l=hills[N-1]-17;l>=hills[0];r--, l--){
        int sum=0;
        for(int j=0;hills[j]<l;j++){
            sum+=(l-hills[j])*(l-hills[j]);
        }
        for(int j=N-1;hills[j]>r;j--){
            sum+=(hills[j]-r)*(hills[j]-r);
        }
        ret = min(ret, sum);
    }

    if(ret == 987654321)
        return 0;
    return ret;
}

void Solution(){
    cout<<calc()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    return 0;
}