#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> nums;

void input(){
    int a;

    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>a;
            nums.push(a);
            if(nums.size()>N)
                nums.pop();
        }
    }
}

void solution(){

    cout<<nums.top()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}