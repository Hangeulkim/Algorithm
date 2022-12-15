#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> answer;
deque<deque<int>*> inside;
deque<int> left, right;

void init(vector<vector<int> > rc){
    answer.resize(rc.size());
    int y=rc.size();
    int x=rc[0].size();
    
    for(int i=0;i<y;++i){
        deque<int> *tmp = new deque<int>;
        
        left.push_back(rc[i][0]);
        for(int j=1;j<x-1;++j){
            tmp->push_back(rc[i][j]);
        }
        inside.push_back(tmp);
        right.push_back(rc[i][x-1]);
    }
}

void Rotate(){
    inside.front()->push_front(left.front());
    right.push_front(inside.front()->back());
    inside.back()->push_back(right.back());
    left.push_back(inside.back()->front());
    
    left.pop_front();
    inside.front()->pop_back();
    right.pop_back();
    inside.back()->pop_front();
}

void ShiftRow(){
    left.push_front(left.back());
    left.pop_back();
    
    inside.push_front(inside.back());
    inside.pop_back();
    
    right.push_front(right.back());
    right.pop_back();
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    init(rc);
    for(int i=0,sz=operations.size();i<sz;++i){
        switch(operations[i][0]){
            case 'R':
                Rotate();
                break;
            case 'S':
                ShiftRow();
                break;
        }
    }
    
    
    for(int i=0,sz=rc.size();i<sz;++i){
        answer[i].push_back(left.front());
        while(!inside.front()->empty()){
            answer[i].push_back(inside.front()->front());
            inside.front()->pop_front();
        }
        answer[i].push_back(right.front());
        
        inside.pop_front();
        left.pop_front();
        right.pop_front();
    }
    
    return answer;
}