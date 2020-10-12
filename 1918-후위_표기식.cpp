#include<bits/stdc++.h>

using namespace std;

string input;
stack<pair<char, int> > opt;
map<char, int> prio;
int gual=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prio['(']=10; prio[')']=10;
    prio['-']=1; prio['+']=1;
    prio['*']=5; prio['/']=5;
    getline(cin,input);
    for(int i=0;i<input.length();i++){
        if(input[i]>='A' && input[i]<='Z'){
            cout<<input[i];
        }

        else if(input[i]=='('){
            gual++;
        }

        else if(input[i]==')'){
            while(!opt.empty()&&gual==opt.top().second){
                cout<<opt.top().first;
                opt.pop();
            }
            gual--;
        }

        else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
            while(!opt.empty()&&gual==opt.top().second&&prio[opt.top().first]>=prio[input[i]]){
                cout<<opt.top().first;
                opt.pop();
            }
            opt.push({input[i],gual});
        }
    }
    while(!opt.empty()){
        cout<<opt.top().first;
        opt.pop();
    }

    return 0;
}
