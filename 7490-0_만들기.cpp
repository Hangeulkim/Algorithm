#include<iostream>
#include<string>

using namespace std;

int T;
int N;
int cnt = 0;

void input(){
    cin>>T;
}

int calc(int num1, int num2, char op){
    switch (op)
    {
    case '+':
        return num1 + num2;
        break;
    
    case '-':
        return num1 - num2;
        break;
    default:
        return -1;
        break;
    }
}

void dfs(int num, char op, int ret, string str, int space){
    if(num == N){
        if(calc(ret, space, op) == 0){
                cout<<str<<'\n';
            }
        
        return;
    }

    int nnum=num+1;
    int nret=calc(ret,space,op);
    dfs(nnum, op ,ret,str+' '+to_string(nnum), space*10+nnum);
    dfs(nnum, '+',nret ,str+'+'+to_string(nnum), nnum);
    dfs(nnum, '-',nret ,str+'-'+to_string(nnum), nnum);
}

void solution(){
    while(T--){
        cin>>N;
        cnt = 0;

        dfs(1,'+', 0, "1",1);
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}