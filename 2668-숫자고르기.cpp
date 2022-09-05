#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int N;
int arr[111];
int chk[111];
vector<int> ans;
stack<int> st;

void dfs(int num){
    int nn = arr[num];

    if(chk[nn]==-1){
        while(!st.empty() && st.top()!=nn){
            chk[st.top()]=1;
            ans.push_back(st.top());
            st.pop();
        }
        ans.push_back(st.top());
        return ;
    }
    else if(chk[nn]==1)
        return ;

    chk[nn]=-1;
    st.push(nn);
    dfs(nn);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
        

    for(int i=1;i<=N;i++){
        if(!chk[i]){
            while(!st.empty()){
                chk[st.top()]=1;
                st.pop();
            }

            chk[i]=-1;
            st.push(i);
            dfs(i);
        }
    }

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<'\n';

    return 0;
}