#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> a;
string input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0,cnt=0;
    cin>>testcase;
    while(testcase--){
        cin>>input;
        while(!a.empty()) a.pop();
        for(int i=0;i<input.length();i++){
            if(!a.empty()&&a.top()==input[i]) a.pop();
            else a.push(input[i]);
        }
        if(a.empty()) cnt++;
    }
    cout<<cnt<<'\n';

    return 0;
}
