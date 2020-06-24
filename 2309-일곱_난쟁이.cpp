#include<bits/stdc++.h>

using namespace std;
int num[10];
vector<int> result;

void dfs(bool chk[10], int idx, int sum, int cnt){
    sum+=num[idx];
    if(cnt>7||sum>100){
        return ;
    }
    chk[idx]=true;
    if(sum==100&&cnt==7){
        for(int i=1;i<=9;i++){
            if(chk[i])
                result.push_back(num[i]);
        }
        return ;
    }
    else{
        for(int i=idx+1;result.empty()&&i<=(3+cnt);i++){
            dfs(chk,i,sum,cnt+1);
            chk[i]=false;
        }
    }
    chk[idx]=false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool chk[10];

    for(int i=1;i<=9;i++){
        cin>>num[i];
        chk[i]=false;
    }

    for(int i=1;i<=3&&result.empty();i++)
        dfs(chk,i,0,1);
    for(int i=0;i<6;i++){
        for(int j=i+1;j<7;j++){
            if(result[i]>result[j]){
                int tmp=result[i];
                result[i]=result[j];
                result[j]=tmp;
            }
        }
    }
    for(auto it : result)
        cout<<it<<'\n';

    return 0;
}
