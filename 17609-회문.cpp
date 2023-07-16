#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int T;
string input;

int dfs(int l, int r, int cnt){
    if(l>r || cnt == 2)
        return cnt;

    if(input[l] == input[r]){
        return dfs(l+1,r-1,cnt);
    }

    else{
        int lcnt = cnt+1, rcnt = cnt+1;
        if(input[l+1] == input[r])
            lcnt = dfs(l+1,r,cnt+1);
        else
            lcnt = 2;
        
        if(input[l] == input[r-1])
            rcnt = dfs(l, r-1, cnt+1);
        else
            rcnt = 2;

        return min(lcnt, rcnt);
    }
}

void solution(){
    cin>>T;
    while(T--){
        cin>>input;

        cout<<dfs(0, input.length() - 1, 0)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}