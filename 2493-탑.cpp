#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

stack<pair<int,int> > stk;
int main(){
    int N=0;
    scanf("%d",&N);
    int tmp=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&tmp);
        while(!stk.empty()&&stk.top().first<tmp){
            stk.pop();
        }

        if(stk.empty()) cout<<0<<" ";
        else cout<<stk.top().second<<" ";
        if(!stk.empty()&&stk.top().first==tmp) stk.pop();
        stk.push(make_pair(tmp,i));
    }


    return 0;
}
