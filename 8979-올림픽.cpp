#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

bool cus_sort(tuple<int,int,int,int> &a , tuple<int,int,int,int> &b){
    if(get<1>(a)==get<1>(b)){
        if(get<2>(a)==get<2>(b))
            return get<3>(a)>get<3>(b);
        return get<2>(a)>get<2>(b);
    }
    return get<1>(a)>get<1>(b);
}


int N, K;
int g,s,b,n;
vector<tuple<int, int, int, int> > arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>n>>g>>s>>b;
        arr.push_back({n,g,s,b});
    }

    sort(arr.begin(),arr.end(),cus_sort);


    int rank=1;
    for(int i=0;i<N;++i){
        if(!(i&&get<1>(arr[i])==get<1>(arr[i-1])&&get<2>(arr[i])==get<2>(arr[i-1])&&get<3>(arr[i])==get<3>(arr[i-1])))
            rank=i+1;

        if(get<0>(arr[i])==K){
            cout<<rank<<'\n';
            break;
        }
    }

    return 0;
}