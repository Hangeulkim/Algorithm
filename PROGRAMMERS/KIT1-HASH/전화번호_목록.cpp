#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    
    int len=phone_book.size();
    for(int i=0;i<len-1;i++){
        int ilen=phone_book[i].length();
        if(ilen>=phone_book[i+1].length())
            continue;
        
        for(int j=0;j<ilen;j++){
            if(phone_book[i][j]!=phone_book[i+1][j])
                break;
            
            if(j==ilen-1)
                answer=false;
        }
        
        if(!answer)
            break;
    }
    
    return answer;
}