#include<bits/stdc++.h>

using namespace std;

map<string, int> run;
string name;

string solution(vector<string> participant, vector<string> completion) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(auto it : participant){
        if(run.find(it)==run.end())
            run[it]=0;
        run[it]++;
    }
    
    for(auto it : completion){
        run[it]--;
    }
    
    string answer;
    for(auto it : run){
        if(it.second != 0){
            answer=it.first;
            break;
        }  
    }
          
    
    return answer;
}