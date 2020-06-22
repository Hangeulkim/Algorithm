#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

int testcase,l,n,input;
vector<int> data;

int fast(vector<int> data){
    int leng=data.size(),max=0;
    for(int i=0;i<leng;i++){
        if(data[i]<=l/2){
            if(max<data[i]) max=data[i];
        }
        else{
            if(max<l-data[i]) max=l-data[i];
        }
    }
    return max;
}

int slow(vector<int> data){
    int leng=data.size();
    if(leng==1&&data[0]==0) return 0;
    if(data[leng-1]<l-data[0]) return l-data[0];
    else return data[leng-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>testcase;
    while(testcase--){
        cin>>l>>n;
        data.clear();
        for(int i=0;i<n;i++){
            cin>>input;
            data.push_back(input);
        }
        sort(data.begin(),data.end());
        cout<<fast(data)<<" "<<slow(data)<<'\n';
    }


    return 0;
}
