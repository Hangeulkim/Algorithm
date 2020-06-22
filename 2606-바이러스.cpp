#include<bits/stdc++.h>

using namespace std;

int com_num,way,num1,num2,cnt=0;
vector<int> input[101];
queue<int> bfs_arr;

bool chk[101]={false,};

void bfs(){
    bfs_arr.push(1);
    while(!bfs_arr.empty()){
        int start=bfs_arr.front();
        chk[start]=true;

        for(int i=0;i<input[start].size();i++){
            if(!chk[input[start][i]]){
                bfs_arr.push(input[start][i]);
                chk[input[start][i]]=true;
            }
        }
        bfs_arr.pop();
        cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>com_num>>way;

    for(int i=0;i<way;i++){
        cin>>num1>>num2;

        input[num1].push_back(num2);
        input[num2].push_back(num1);
    }

    bfs();

    cout<<cnt-1<<'\n';

    return 0;
}
