#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

//���� �� ���ÿ� �־��� �� ����? -> ���ڼ� �̹Ƿ� ���� �� ���� sqrt
vector<pair<int, int> > cnt;
vector<pair<int, int> > start_arr;

bool cmp(const pair<int, int>& a, const pair<int, int>& b ){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second; 
}

void calc(int e){
    for(int i=0;i<=e;++i){
        cnt[i].first=i;
        cnt[i].second=0;
    }
    
    for(int i=1;i<=sqrt(e);++i){
        for(int j=i;j*i<=e;++j){
            cnt[i*j].first=i*j;
            if(i==j)
                cnt[i*j].second+=1;
            else
                cnt[i*j].second+=2;
        }
    }
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer(starts.size());
    cnt.resize(e+1);//���� ���� �ִ� e���� �ۿ� �ȳ����Ƿ�
    
    int len=starts.size();
    for(int i=0;i<len;++i){
        start_arr.push_back({starts[i],i});
    }
    sort(start_arr.begin(),start_arr.end());
    calc(e);
    sort(cnt.begin(),cnt.end(),cmp);
    
    int idx=0;
    for(int i=0;i<len;++i){
        while(cnt[idx].first < start_arr[i].first)
            ++idx;
        answer[start_arr[i].second] = cnt[idx].first;

    }
    
    
    return answer;
}