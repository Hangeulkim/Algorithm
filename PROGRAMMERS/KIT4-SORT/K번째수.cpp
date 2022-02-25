#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for(auto it : commands){
        int i=it[0]-1;
        int j=it[1];
        int k=it[2]-1;
        
        tmp.assign(array.begin()+i,array.begin()+j);
        sort(tmp.begin(),tmp.end());
        
        answer.push_back(tmp[k]);
    }
    
    return answer;
}