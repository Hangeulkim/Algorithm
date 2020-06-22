#include<iostream>
#include<vector>
#include<functional>
#include<queue>

using namespace std;
long long int result=0;

priority_queue<int> cnt[300001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N=0,P=0;
    cin>>N>>P;
    int tmp1=0,tmp2=0;
    while(N--){
        cin>>tmp1>>tmp2;
        if(cnt[tmp1].empty()||cnt[tmp1].top()<tmp2){
            result++;
            cnt[tmp1].push(tmp2);
        }
        else if(cnt[tmp1].top()==tmp2) continue;
        else{
            while(cnt[tmp1].top()>tmp2){
                result++;
                cnt[tmp1].pop();
                if(cnt[tmp1].empty()||cnt[tmp1].top()<tmp2){
                    result++;
                    cnt[tmp1].push(tmp2);
                }
                else if(cnt[tmp1].top()==tmp2) break;
            }
        }
    }
    cout<<result<<'\n';
    return 0;
}
