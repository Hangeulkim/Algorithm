#include <string>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>

using namespace std;

struct Node{
    int id,left,right;
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'O');
    stack<Node> st;
    vector<Node> list;
    
    for(int i=0;i<=n;i++){
        list.push_back({i,i-1,i+1});
    }
    
    
    for(int i=0;i<cmd.size();i++){
        switch(cmd[i][0]){
            case 'U':{
                int num=stoi(&cmd[i][2]);
                while(num--){
                    k=list[k].left;
                }
                
                break;
            }
            
            case 'D':{
                int num=stoi(&cmd[i][2]);
                while(num--){
                    k=list[k].right;
                }
                
                break;
            }
            
            case 'C':{
                Node tmp=list[k];
                answer[tmp.id]='X';
                
                st.push(tmp);
                
                if(tmp.left != -1){
                    list[tmp.left].right=tmp.right;
                }
                    
                if(tmp.right != n){
                    list[tmp.right].left=tmp.left;
                    k=tmp.right;
                }
                else
                    k=tmp.left;
                    
                break;
            }
            
            case 'Z':{
                Node tmp=st.top();
                st.pop();
                
                answer[tmp.id]='O';
                if(tmp.left != -1)
                    list[tmp.left].right=tmp.id;
                if(tmp.right != n)
                    list[tmp.right].left=tmp.id;
            
                break;
            }
        }
    }
    
    
    return answer;
    
}