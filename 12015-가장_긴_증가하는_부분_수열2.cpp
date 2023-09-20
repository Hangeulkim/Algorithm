#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> lis;

void input(){
    int tmp;

    cin>>N;
    cin>>tmp;
    lis.push_back(tmp);
}

int bs(int l, int r, int num){
    int mid;

    while(l<r){
        mid = (l + r)/2;

        if(lis[mid] < num)
            l = mid + 1;
        else
            r = mid;
    }

    return r;
}

void solution(){
    int tmp;


    for(int i=1;i<N;++i){
        cin>>tmp;

        if(tmp > lis.back()){
            lis.push_back(tmp);
        }
        else{
            int idx = bs(0, lis.size(), tmp);
            lis[idx] = tmp;
        }
    }

    cout<<lis.size()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}