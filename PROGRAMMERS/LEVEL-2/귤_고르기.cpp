#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int chk[10'000'001];
vector<int> gul;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int len = tangerine.size();
    
    for(int i=0;i<len;++i){
        ++chk[tangerine[i]];
    }
    
    for(int i=1;i<10'000'001;++i){
        if(chk[i])
            gul.push_back(chk[i]);
    }
    
    sort(gul.begin(),gul.end(),greater<int>());
    
    for(int i=0;i<gul.size();++i){
        k-=gul[i];
        ++answer;
        if(k<=0)
            break;
    }
    
    
    return answer;
}