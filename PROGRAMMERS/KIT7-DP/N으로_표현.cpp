#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> dp[9];

int solution(int N, int number) {
    
    if(number==N)
        return 1;
    
    dp[1].insert(N);
    for(int i=2;i<9;i++)
        dp[i].insert(*dp[i-1].begin()*10+N);
    
    for(int i=2;i<9;i++){
        for(int j=1;j<i;j++){
            for(auto it1 : dp[j]){
                for(auto it2 : dp[i-j]){
                    dp[i].insert(it1*it2);
                    dp[i].insert(it1+it2);
                    dp[i].insert(it1-it2);
                    if(it2!=0)
                        dp[i].insert(it1/it2);
                }
            }
        }
        if(dp[i].find(number)!=dp[i].end())
            return i;
    }
    
    return -1;
}