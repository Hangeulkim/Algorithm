#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N,tmp;
int ret=0;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;

        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        int l=0,r=N-1;

        while(1){
             if(l==i) l++;
             if(r==i) r--;
             if(l>=r) break;
             if(v[l]+v[r]<v[i]) l++;
             else if(v[l]+v[r]>v[i]) r--;
             else{
                ret++;
                break;
             }
        }
    }

    cout<<ret<<'\n';;

    return 0;
}