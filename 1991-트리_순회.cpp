#include<bits/stdc++.h>

using namespace std;

typedef struct data{
    char left,right;
}dat;

int N;
map<char,dat> tr;


void preorder(char input){
    cout<<input;
    char left=tr[input].left;
    char right=tr[input].right;
    if(left != '.')
        preorder(left);
    if(right != '.')
        preorder(right);
}

void inorder(char input){
    char left=tr[input].left;
    char right=tr[input].right;
    if(left != '.')
        inorder(left);
    cout<<input;
    if(right != '.')
        inorder(right);
    
}

void postorder(char input){
    char left=tr[input].left;
    char right=tr[input].right;
    if(left != '.')
        postorder(left);
    if(right != '.')
        postorder(right);
    cout<<input;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    char a,b,c;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        tr.insert({a,{b,c}});
    }

    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postorder('A');


    return 0;
}