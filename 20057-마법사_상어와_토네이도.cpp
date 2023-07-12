#include<iostream>

using namespace std;

int N;
int A[501][501];

int my[4] = { 0, 1, 0, -1 };
int mx[4] = { -1, 0, 1, 0 };

int tmy[4][10] = { { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
                    { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, 
                    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
                    { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };
 
int tmx[4][10] = { { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} ,
                    { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
                    { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
                    { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 } };

int tornado[10] = { 1, 1, 7, 7, 10, 10, 2, 2, 5, 0};

void input(){
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>A[i][j];
        }
    }
}

int move_sand(int m, int y, int x){
    int ny = y+my[m], nx=x+mx[m];
    int out = 0, sand = A[ny][nx], cnt = 0;
    A[ny][nx]=0;

    if(sand == 0)
        return 0;

    for(int i=0;i<10;++i){
        ny = y+tmy[m][i];
        nx = x+tmx[m][i];
        int swept = sand * tornado[i] / 100;
        cnt += swept;

        if(ny<0||nx<0||ny>=N||nx>=N){
            if(i == 9)
                out += sand - cnt;
            
            else
                out += swept;
        }
            
        else{
            if(i == 9)
                A[ny][nx] += sand - cnt;

            else
                A[ny][nx] += swept;
        }
            
    }

    return out;
}

int calc(){
    int answer = 0;
    int move_cnt = 1;
    int y=N/2, x=N/2;
    while(1){
        for(int i=0;i<4;++i){
            for(int j=0;j<move_cnt;++j){
                answer += move_sand(i, y, x);
                
                y+=my[i];
                x+=mx[i];

                if(y==0 && x==0)
                    return answer;
            }
            
            if(i%2 == 1)
                ++move_cnt;
        }
    }
}

void solution(){
    int answer = 0;

    answer = calc();
    
    cout<<answer<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}