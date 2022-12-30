#include <string>
#include <vector>

using namespace std;

int answer = 1;
vector<int> way[17];
bool vst[1<<17];
int N;

void dfs(vector<int>& info, int sheep, int wolf, int chk){
    answer = max(sheep,answer);
    
    for(int i=0;i<N;++i){
        if(1 & chk>>i){
            for(int j=0,sz=way[i].size();j<sz;++j){
                int next=way[i][j];
                int nchk = (chk | 1<<next);
                int nsheep = sheep + (info[next]==0);
                int nwolf  = wolf + (info[next]==1);

                if(nsheep <= nwolf || (vst[nchk]))
                    continue;

                vst[nchk]=true;
                dfs(info, nsheep, nwolf, nchk);
            }
        }
        
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    N=info.size();
    for(int i=0,sz=edges.size();i<sz;++i){
        way[edges[i][0]].push_back(edges[i][1]);
    }
    vst[1]=true;
    dfs(info,1,0,1);
    
    return answer;
}