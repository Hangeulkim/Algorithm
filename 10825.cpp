#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
#include<string>

using namespace std;

vector< tuple<string,int,int,int> > result;

bool comp(const tuple<string,int,int,int>& a,const tuple<string,int,int,int>& b){
    if(get<1>(a)!=get<1>(b)) return get<1>(a)>get<1>(b);
    else if(get<2>(a)!=get<2>(b)) return get<2>(a)<get<2>(b);
    else if(get<3>(a)!=get<3>(b)) return get<3>(a)>get<3>(b);
    else return get<0>(a).compare(get<0>(b))<0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0;
    string tmp;
    int kor=0,eng=0,math=0;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>tmp>>kor>>eng>>math;
        result.push_back(tuple<string,int,int,int>(tmp,kor,eng,math));
    }
    sort(result.begin(),result.end(),comp);
    for(auto it=result.begin();it!=result.end();it++) cout<<get<0>(*it)<<'\n';
    return 0;
}
