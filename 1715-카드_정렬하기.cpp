#include<bits/stdc++.h>

using namespace std;
int sum,tmp1,tmp2;
int N;
priority_queue<int,vector<int>,greater<int> > input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0; i<N;i++){
        cin>>tmp1;
        input.push(tmp1);
    }

    if(N==1)
        cout<<0<<'\n';
    else{
        while(input.size()!=1){
            tmp1=input.top();
            input.pop();
            tmp2=input.top();
            input.pop();

            sum+=tmp1+tmp2;
            input.push(tmp1+tmp2);
        }

        cout<<sum<<'\n';
    }

    return 0;
}
