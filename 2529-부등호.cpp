#include<bits/stdc++.h>

using namespace std;

int N;
vector<char> input;
char tmp;
vector<int> big,small;
bool big_finish=false,small_finish=false;
bool big_bool[10],small_bool[10];

bool big_chk(int loc,int num){
    if(loc==0) return true;
    if(input[loc]=='<'){
        if(big[loc-1]<num) return true;
    }
    else{
        if(big[loc-1]>num) return true;
    }
    return false;
}

bool small_chk(int loc,int num){
    if(loc==0) return true;
    if(input[loc]=='<'){
        if(small[loc-1]<num) return true;
    }
    else{
        if(small[loc-1]>num) return true;
    }
    return false;
}

void dfs_big(int loc){
    if(big_finish) return;
    for(int i=9;i>=0;i--){
        if(!big_bool[i]&&big_chk(loc,i)){
            big.push_back(i);
            big_bool[i]=true;
            if(loc==N){
                big_finish=true;
                return;
            }
            dfs_big(loc+1);
            if(big_finish) return;
            big_bool[i]=false;
            big.pop_back();
        }
    }
}

void dfs_small(int loc){
    if(small_finish) return;
    for(int i=0;i<=9;i++){
        if(!small_bool[i]&&small_chk(loc,i)){
            small.push_back(i);
            small_bool[i]=true;
            if(loc==N){
                small_finish=true;
                return;
            }
            dfs_small(loc+1);
            if(small_finish) return;
            small_bool[i]=false;
            small.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    input.push_back('0');
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    dfs_big(0);
    dfs_small(0);

    for(int i=0;i<=N;i++){
        cout<<big[i];
    }
    cout<<'\n';
    for(int i=0;i<=N;i++){
        cout<<small[i];
    }

    return 0;
}
