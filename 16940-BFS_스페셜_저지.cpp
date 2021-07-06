#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> arr[100001];
int input[100001];

bool chk[100001];
queue<int> vis;
set<int> s;

int bfs(){
    if(vis.front()!=1)
        return 0;
    vis.pop();
    
    queue<int> q;
    q.push(1);
    chk[1]=true;

    while(!vis.empty()){
        int num=q.front();
        q.pop();
        s.clear();
        
        for(auto it : arr[num]){
            if(chk[it]!=0)
                continue;
            s.insert(it);
            chk[it]=true;
        }

        for(int i=0;i<s.size();i++){
            int tmp = vis.front();
            if(s.find(tmp)==s.end()) 
                return 0;
            q.push(tmp);
            vis.pop();
        }
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int a,b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        cin>>a;
        vis.push(a);
    }
    
    cout<<bfs();

    return 0;
}