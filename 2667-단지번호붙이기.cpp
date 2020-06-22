#include<bits/stdc++.h>

using namespace std;
int N=0;
string tmp;
vector<string> input;
vector<int> result;

void bfs(){
    int cnt=0;
    static int danzi=0;
    bool find_flag=false;
    queue<pair<int,int> > bfs_arr;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(input[i][j]=='1'){
                find_flag=true;
                bfs_arr.push(make_pair(i,j));
                break;
            }
        }
        if(find_flag) break;
    }

    if(find_flag){
        while(!bfs_arr.empty()){
            int y=bfs_arr.front().first;
            int x=bfs_arr.front().second;

            if(y+1<N&&input[y+1][x]=='1'){
                bfs_arr.push(make_pair(y+1,x));
                input[y+1][x]='0';
            }
            if(y-1>=0&&input[y-1][x]=='1'){
                bfs_arr.push(make_pair(y-1,x));
                input[y-1][x]='0';
            }
            if(x+1<N&&input[y][x+1]=='1'){
                bfs_arr.push(make_pair(y,x+1));
                input[y][x+1]='0';
            }
            if(x-1>=0&&input[y][x-1]=='1'){
                bfs_arr.push(make_pair(y,x-1));
                input[y][x-1]='0';
            }

            input[y][x]='0';
            cnt++;
            bfs_arr.pop();
        }
        result.push_back(cnt);

        bfs();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    bfs();

    sort(result.begin(),result.end(),less<int>());

    cout<<result.size()<<'\n';
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<'\n';
    }


    return 0;
}
