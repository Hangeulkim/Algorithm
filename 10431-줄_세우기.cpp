#include<iostream>
#include<vector>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;++i){
        vector<int> children(20);

        int tmp, cnt=0;
        cin>>tmp;
        for(int j=0;j<20;++j)
            cin>>children[j];

        for(int j=0;j<20;++j){
            for(int k=0;k<j;++k){
                if(children[k]>children[j]){
                    cnt+=j-k;
                    tmp = children[j];
                    children.insert(children.begin()+k,tmp);
                    children.erase(children.begin()+j+1);
                    break;
                }
            }
        }

        cout<<i<<" "<<cnt<<'\n';
    }

    return 0;
}