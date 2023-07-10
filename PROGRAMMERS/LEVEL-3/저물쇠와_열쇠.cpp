#include <string>
#include <vector>

using namespace std;

bool calc(vector<vector<int>> key, vector<vector<int>> lock){
    int M = key.size(), N = lock.size();
    
    for(int si=-N;si<N;++si){
        for(int sj=-N;sj<N;++sj){
            bool flag = true;
            
            for(int i=0;i<N && flag;++i){
                for(int j=0;j<N && flag;++j){
                    int y = si + i;
                    int x = sj + j;
                    if(!lock[i][j]){
                        if(y>=0 && y<M && x>=0 && x<M)
                            flag = key[y][x];
                            
                        else
                            flag = false;
                    }
                    else{
                        if(y>=0 && y<M && x>=0 && x<M && key[y][x])
                            flag = false;
                    }
                }
            }

            if(flag)
                return true;
        }
    }
    
    return false;
}

vector<vector<int>> turn(vector<vector<int> > key){
    vector<vector<int> > tkey = key;
    int M = key.size();
    
    for(int i=0;i<M;++i){
        for(int j=M-1,tj=0;j>=0;--j, ++tj){
            tkey[i][tj] = key[j][i];
        }
    }
    
    return tkey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    for(int i=0;i<4;++i){
        answer = calc(key, lock);
        
        if(answer)
            return answer;
        key = turn(key);
    }
    return answer;
}