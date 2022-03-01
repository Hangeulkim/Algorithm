#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int f=0,b=people.size()-1;
    
    sort(people.begin(),people.end());
    while(f<=b){
        answer++;
        if(people[f]<=limit-people[b])
            f++;
        b--;
    }
    
    return answer;
}