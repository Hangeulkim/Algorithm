#include <string>
#include <vector>
#include <cmath>


using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int w,h;
    for(w=3;w<=brown/2-1;w++){
        h=brown/2-w+2;
        if(w + h - 2 == brown/2 && (w-2)*(h-2) == yellow){
            answer.push_back(max(w,h));
            answer.push_back(min(w,h));
            break;
        }
    }
    
    return answer;
}