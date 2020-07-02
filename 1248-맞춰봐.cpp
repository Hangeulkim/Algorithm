#include<bits/stdc++.h>

using namespace std;

int N;
char input[11][11];
bool endf=false;
int arr[11];

bool chk(int num){
    int tmp=arr[num];
    for(int i=num+1;i<=N;i++){
        tmp+=arr[i];
        if(input[num][i]=='+'&&tmp<=0){
            return false;
        }
        else if(input[num][i]=='-'&&tmp>=0){
            return false;
        }
        else if(input[num][i]=='0'&&tmp!=0){
            return false;
        }
    }
    return true;
}

void dfs(int num){
    if(num==-1){
        endf=true;
        return ;
    }

    if(input[num][num]=='+'){
        for(int i=1;i<=10&&!endf;i++){
            arr[num]=i;
            if(chk(num)){
                dfs(num-1);
            }
        }
    }
    else if(input[num][num]=='-'){
        for(int i=-1;i>=-10&&!endf;i--){
            arr[num]=i;
            if(chk(num)){
                dfs(num-1);
            }
        }
    }
    else{
        arr[num]=0;
        dfs(num-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            cin>>input[i][j];
        }
    }
    dfs(N);
    for(int i=1;i<=N;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
