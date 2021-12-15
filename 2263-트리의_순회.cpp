#include<bits/stdc++.h>

using namespace std;

int n;
int in[100001];
int post[100001];
int idx[100001];

void pre(int inbegin,int inend, int pobegin, int poend){
    if(inbegin > inend || pobegin > poend)
        return;

    int root = idx[post[poend]];
    int left = root - inbegin;

    cout<<in[root]<<" ";

    pre(inbegin, root-1, pobegin, pobegin+left-1);
    pre(root+1,inend,pobegin+left,poend-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
        idx[in[i]] = i;
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }


    pre(0,n-1,0,n-1);

    return 0;
}