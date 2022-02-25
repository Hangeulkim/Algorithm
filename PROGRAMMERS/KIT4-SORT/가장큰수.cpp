#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(string& a, string& b){
    int ac=0,bc=0,alen=a.length(),blen=b.length(),cnt=0;
    while(1){
        if(a[ac]==b[bc]){
            cnt++;
            if(cnt==4)
                return a > b;
            
            ac=(ac+1)%alen;
            bc=(bc+1)%blen;
        }
        else{
            return a[ac] > b[bc];
        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    
    for(auto it : numbers){
        nums.push_back(to_string(it));
    }
    
    sort(nums.begin(),nums.end(),cmp);
    
    for(auto it : nums)
        answer.append(it);
    
    if(answer[0]=='0')
        answer="0";
    return answer;
}