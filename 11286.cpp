#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int ans(int a){
    if(a<0) return -a;
    return a;
}

auto cmp=[](int left,int right){
    if(ans(left)!=ans(right)) return ans(left)>ans(right);
    else return left>right;
};
priority_queue<int,vector<int>, decltype(cmp)> pq(cmp);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp=0,testcase=0;
    cin>>testcase;
    while(testcase--){
        cin>>tmp;
        if(tmp==0){
            if(pq.size()==0) cout<<"0"<<'\n';
            else{
                int tmp2=pq.top();
                pq.pop();
                cout<<tmp2<<'\n';
            }
        }
        else pq.push(tmp);
    }

    return 0;
}
