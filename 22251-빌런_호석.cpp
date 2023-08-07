#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int costs[10][10];
int num[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
int N,K,P,X;
string Xstr;
int ans;

void input(){
    cin>>N>>K>>P>>X;

    //숫자 별로 서로 몇 개의 led를 바꿔야 하는지를 계산
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<7;++k){
                costs[i][j] += (num[i][k] != num[j][k]);
            }
        }
    }

    //K보다 자릿수가 적은 경우를 해결하기 위해 문자열로 변경
    X += 10'000'000;
    for(int i=0;i<K;++i){
        Xstr.push_back(X%10+'0');
        X/=10;
    }
    reverse(Xstr.begin(),Xstr.end());
}

void dfs(int num, int cost, string nstr){
    if(num == K){
        int nnstr = stoi(nstr);
        if(nnstr <= N && nnstr >= 1)
            ++ans;
        return;
    }

    for(int i=0;i<10;++i){ 
        int strNum = nstr[num]-'0';
        int ncost = costs[i][strNum] + cost;

        //변경 된 이후 숫자로 변환하여 범위 내 인지 체크
        string copy = nstr;
        copy[num] = i + '0';
        if(ncost <= P){
            dfs(num+1, ncost, copy);
        }
    }
}

void solution(){
    dfs(0, 0, Xstr);

    //아무것도 안바꾸는 경우를 제외하고 출력
    cout<<ans-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}