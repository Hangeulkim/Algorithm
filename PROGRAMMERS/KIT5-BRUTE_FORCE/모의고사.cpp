#include <string>
#include <vector>

using namespace std;

int supo[3][10]={
    {1,2,3,4,5},
    {2,1,2,3,2,4,2,5},
    {3,3,1,1,2,2,4,4,5,5}
};
int asz=5,bsz=8,csz=10;
int ac=0,bc=0,cc=0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i]==supo[0][i%asz])
            ac++;
        if(answers[i]==supo[1][i%bsz])
            bc++;
        if(answers[i]==supo[2][i%csz])
            cc++;
    }
    
    int num=max(ac,max(bc,cc));
    if(ac==num)
        answer.push_back(1);
    if(bc==num)
        answer.push_back(2);
    if(cc==num)
        answer.push_back(3);
    
    return answer;
}