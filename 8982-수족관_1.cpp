#include<bits/stdc++.h>

using namespace std;

int N,M;
int fx, fy, sx, sy;
int result,row;
pair<int, int> d[40001];
vector<int> bye;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    cin>>fx>>fy;
    for(int i=0;i<N/2-1;i++){
        cin>>fx>>fy>>sx>>sy;
        for(int j=fx;j<sx;j++){
            d[j].first=fy;
        }
    }
    cin>>fx>>fy;

    row=fx;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>fx>>fy>>sx>>sy;
        bye.push_back(fx);
    }
    for(int i=0;i<bye.size();i++){
        fx=bye[i];
        int h=d[fx].first;
        d[fx].second=h;

        for(int j=fx-1;j>=0;j--){
            h=min(h,d[j].first);
            d[j].second=max(d[j].second,h);
        }
        h=d[fx].first;
        for(int j=fx+1;j<row;j++){
            h=min(h,d[j].first);
            d[j].second=max(d[j].second,h);
        }
    }
    result=0;
    for(int i=0;i<row;i++)
        result+=d[i].first - d[i].second;
    cout<<result<<'\n';

    return 0;
}
