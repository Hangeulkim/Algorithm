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

    //���� ���� ���� �� ���� led�� �ٲ�� �ϴ����� ���
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<7;++k){
                costs[i][j] += (num[i][k] != num[j][k]);
            }
        }
    }

    //K���� �ڸ����� ���� ��츦 �ذ��ϱ� ���� ���ڿ��� ����
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

        //���� �� ���� ���ڷ� ��ȯ�Ͽ� ���� �� ���� üũ
        string copy = nstr;
        copy[num] = i + '0';
        if(ncost <= P){
            dfs(num+1, ncost, copy);
        }
    }
}

void solution(){
    dfs(0, 0, Xstr);

    //�ƹ��͵� �ȹٲٴ� ��츦 �����ϰ� ���
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