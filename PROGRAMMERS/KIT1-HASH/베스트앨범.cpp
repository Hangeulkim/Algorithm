#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


bool cmp(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b){
    if(a.second == b.second)
        return a.second < b.second;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, vector<pair<int,int> > > li;
    map<string, int> genre;
    
    for(int i=0;i<genres.size();i++){
        if(genre.find(genres[i])==genre.end())
            genre[genres[i]]=0;
            
        genre[genres[i]]+=plays[i];
        li[genres[i]].push_back({i,plays[i]});
    }
    
    vector<pair<string, int> > g(genre.begin(), genre.end());
    sort(g.begin(),g.end(),cmp);
    
    for(auto it : g){
        vector<pair<int, int> >tmp(li[it.first].begin(), li[it.first].end());
        sort(tmp.begin(),tmp.end(),cmp2);
        
        answer.push_back(tmp[0].first);
        if(tmp.size()>1)
            answer.push_back(tmp[1].first);
        
    }
    
    return answer;
}