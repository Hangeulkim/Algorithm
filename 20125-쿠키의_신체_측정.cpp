#include<iostream>
#include<vector>

using namespace std;

int N;
string tmp;
vector<string> board;
int hy,hx;

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

void input(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>tmp;
        board.push_back(tmp);
    }
}

void findHead(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(board[i][j]=='*'){
                hy=i+1;
                hx=j;
                cout<<hy+1<<" "<<hx+1<<'\n';
                return;
            }
        }
    }
}

int findPart(int sy, int sx, int m){
    int cnt=0;
    while(sy>=0&&sx>=0&&sy<N&&sx<N&&board[sy][sx]=='*'){
        ++cnt;
        sy+=my[m];
        sx+=mx[m];
    }

    cout<<cnt<<" ";
    return cnt;
}

void findParts(){
    findPart(hy,hx-1,2);
    findPart(hy,hx+1,0);
    int leng = findPart(hy+1,hx,1);
    findPart(hy+leng+1,hx-1,1);
    findPart(hy+leng+1,hx+1,1);
}

void solution(){
    findHead();
    findParts();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}