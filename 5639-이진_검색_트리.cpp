#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
node *root = NULL;

void ins(int num){
    node *nd = new node;
    nd->data = num;
    nd->left = NULL;
    nd->right = NULL;

    if(root == NULL){
        root = nd;
        return ;
    }

    node *tmp = root;
    while(true){
        if(num < tmp -> data){
            if(tmp -> left == NULL){
                tmp -> left = nd;
                return;
            }
            else{
                tmp = tmp -> left;
            }
        }
        if(num > tmp -> data){
            if(tmp -> right == NULL){
                tmp -> right = nd;
                return;
            }
            else{
                tmp = tmp -> right;
            }
        }
    }
}

void pos(node *nd){
    if(nd->left != NULL){
        pos(nd->left);
    }
    if(nd->right != NULL){
        pos(nd->right);
    }

    cout<<nd->data<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    
    while(cin>>num)
        ins(num);
    pos(root);

    return 0;
}