#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end());
    
    int st=-30000,ed=30000;
    for(int i=0;i<routes.size();i++){
        if(routes[i][0]>=st&&routes[i][0]<=ed){
            if(ed>routes[i][1])
                ed=routes[i][1];
            if(st<routes[i][0])
                st=routes[i][0];
        }
        else{
            st=routes[i][0];
            ed=routes[i][1];
            answer++;
        }
    }
    
    return answer;
}