#include <string>
#include <vector>

using namespace std;

int chka[10001], chkb[10001];
int N;
int a,b;

void init(vector<int> topping){
    fill(&chka[0],&chka[10001],0);
    fill(&chkb[0],&chkb[10001],0);
    
    a=b=0;
    N=topping.size();
    for(int i=0;i<N;++i){
        int num=topping[i];
        
        if(!chkb[num])
            ++b;
        ++chkb[num];
    }
}

int calc(vector<int> topping){
    int ans=0;
    
    for(int i=0;i<N;++i){
        int num=topping[i];
        
        --chkb[num];
        if(!chkb[num])
            --b;
        if(!chka[num])
            ++a;
        ++chka[num];
        
        if(a==b)
            ++ans;
    }
    
    return ans;
}

int solution(vector<int> topping) {
    int answer = -1;
    
    init(topping);
    answer=calc(topping);
    
    return answer;
}