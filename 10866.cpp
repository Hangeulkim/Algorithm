#include<iostream>
#include<deque>
#include<string>

using namespace std;

deque<int> dq;
string input;
int tmp=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0;
    cin>>testcase;
    while(testcase--){
        cin>>input;
        if(input=="push_front"){
            cin>>tmp;
            dq.push_front(tmp);
        }
        else if(input=="push_back"){
            cin>>tmp;
            dq.push_back(tmp);
        }
        else if(input=="pop_front"){
            if(dq.empty()) cout<<"-1"<<'\n';
            else {
                tmp=dq.front();
                dq.pop_front();
                cout<<tmp<<'\n';
            }
        }
        else if(input=="pop_back"){
            if(dq.empty()) cout<<"-1"<<'\n';
            else {
                tmp=dq.back();
                dq.pop_back();
                cout<<tmp<<'\n';
            }
        }
        else if(input=="size"){
            cout<<dq.size()<<'\n';
        }
        else if(input=="empty"){
            if(dq.empty()) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        }
        else if(input=="front"){
            if(dq.empty()) cout<<"-1"<<'\n';
            else cout<<dq.front()<<'\n';
        }
        else if(input=="back"){
            if(dq.empty()) cout<<"-1"<<'\n';
            else cout<<dq.back()<<'\n';
        }
    }



    return 0;
}
