#include <string>
#include <vector>
#include <iostream>

using namespace std;

int presum[1111][1111];
int N,M;

int calc(vector<vector<int>>& board, vector<vector<int>>& skill){
    for(int i=0,sz=skill.size();i<sz;++i){
        int r1=skill[i][1];
        int c1=skill[i][2];
        int r2=skill[i][3];
        int c2=skill[i][4];
        int degree=skill[i][0]==1?-skill[i][5]:skill[i][5];
        
        presum[r1][c1]+=degree;
        presum[r2+1][c1]-=degree;
        presum[r1][c2+1]-=degree;
        presum[r2+1][c2+1]+=degree;
    }
    
    for(int i=1;i<=N;++i){
        for(int j=0;j<M;++j){
            presum[i][j]+=presum[i-1][j];
        }
    }
    
    for(int j=1;j<=M;++j){
        for(int i=0;i<N;++i){
            presum[i][j]+=presum[i][j-1];
        }
    }
    
    int answer=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(presum[i][j]+board[i][j]>0)
                ++answer;
        }
    }
    return answer;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    N = board.size();
    M = board[0].size();
    
    answer = calc(board, skill);
    
    return answer;
}