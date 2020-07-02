#include<bits/stdc++.h>

using namespace std;

int N;
vector<string> a;
map<char, int> in;
vector<int> arr;
string tmpstr;
long long num=0;

void find(){
    long long sum=0;
    for(int i=0;i<N;i++){
        long long tmp=0;
        for(int j=0;j<a[i].length();j++,tmp*=10){
            tmp+=in[a[i][j]];
        }
        sum+=tmp;
    }
    num=max(num,sum/10);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmpstr;
        a.push_back(tmpstr);
        for(int j=0;j<tmpstr.length();j++)
            in[tmpstr[j]]=-1;
    }

    int len=in.size();
    for(int i=9;i>=10-len;i--){
        arr.push_back(i);
    }

    do {
        int cnt=0;
        for(auto it : in){
            in[it.first]=arr[cnt++];
        }
        find();
    } while(prev_permutation(arr.begin(),arr.end()));
    cout<<num<<'\n';

    return 0;
}
