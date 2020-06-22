#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<string>

using namespace std;

int vote[4][4];
int sum[4];

vector< tuple <int,int,int,int,int> > result;
bool comp(const tuple<int,int,int,int,int>& a,const tuple<int,int,int,int,int>& b){
    if(get<0>(a)!=get<0>(b)) return get<0>(a)>get<0>(b);
    else if(get<1>(a)!=get<1>(b)) return get<1>(a)>get<1>(b);
    else if(get<2>(a)!=get<2>(b)) return get<2>(a)>get<2>(b);
    else return get<3>(a)>get<3>(b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<4;i++)
        for(int j=1;j<4;j++)
            vote[i][j]=0;
    for(int i=1;i<4;i++) sum[i]=0;
    int testcase=0;
    cin>>testcase;
    int tmp1=0,tmp2=0,tmp3=0;
    for(int i=1;i<=testcase;i++){
        cin>>tmp1>>tmp2>>tmp3;
        vote[1][tmp1]+=1;
        vote[2][tmp2]+=1;
        vote[3][tmp3]+=1;
    }
    for(int i=1;i<4;i++)
        for(int j=1;j<4;j++)
            sum[i]+=vote[i][j]*j;
    for(int i=1;i<4;i++) result.push_back(make_tuple(sum[i],vote[i][3],vote[i][2],vote[i][1],i));
    sort(result.begin(),result.end(),comp);
    if(get<0>(result[0])==get<0>(result[1])&&get<1>(result[0])==get<1>(result[1])&&get<2>(result[0])==get<2>(result[1])&&get<3>(result[0])==get<3>(result[1])) cout<<"0 "<<get<0>(result[0]);
    else cout<<get<4>(result[0])<<" "<<get<0>(result[0]);
    return 0;
}
