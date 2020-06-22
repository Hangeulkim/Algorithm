#include<bits/stdc++.h>

using namespace std;

vector<int> input;
int N,tmp;

void dfs(vector<int> a,int num){
    if(a.size()==6){
        for(int i=0;i<6;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return ;
    }

    for(int i=num;i<=N-6+a.size();i++){
        a.push_back(input[i]);
        dfs(a,i+1);
        a.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    while(true){
        input.clear();

        cin>>N;
        if(N==0) break;
        for(int i=0;i<N;i++){
            cin>>tmp;
            input.push_back(tmp);
        }
        vector<int> n;
        dfs(n,0);
        cout<<"\n";
    }

    return 0;
}
