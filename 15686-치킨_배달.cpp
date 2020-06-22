#include<bits/stdc++.h>

using namespace std;

int N,M,min_num=987654321;

vector<pair<int, int> > house, chicken;

void calc(vector<int> input){
    int house_num=house.size(),sum=0;

    for(int i=0;i<house_num;i++){
        int tmp_min=987654321;
        for(int j=0;j<M;j++){
            int tmp=abs(house[i].first-chicken[input[j]].first)+abs(house[i].second-chicken[input[j]].second);

            if(tmp_min>tmp) tmp_min=tmp;
        }
        sum+=tmp_min;
    }
    if(min_num>sum) min_num=sum;
}

void find(int num, vector<int> input){
    int house_num=house.size(),chicken_num=chicken.size();

    for(int i=num;i<chicken_num;i++){
        input.push_back(i);
        if(input.size()==M){
            calc(input);
        }
        find(i+1,input);
        input.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;

    int tmp;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tmp;
            if(tmp==1){
                house.push_back(make_pair(i,j));
            }
            else if(tmp==2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    vector<int> chicken_sum;
    find(0,chicken_sum);

    cout<<min_num<<'\n';

    return 0;
}
