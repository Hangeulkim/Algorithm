#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

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
