#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

queue<int> input;
stack<int> space;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0,tmp=0;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>tmp;
        input.push(tmp);
    }
    for(int i=1;i<=testcase;i++){
        if(!(input.empty())&&input.front()==i){
            input.pop();
        }
        else if(!(input.empty())&&input.front()!=i){
            if(space.empty()||space.top()!=i){
                space.push(input.front());
                input.pop();
                i--;
                continue;
            }
            else if(space.top()==i){
                space.pop();
            }
        }
        else if(!(space.empty())&&space.top()==i){
            space.pop();
        }
        else{
            cout<<"Sad"<<'\n';
            return 0;
        }
    }
    cout<<"Nice"<<'\n';
    return 0;
}
