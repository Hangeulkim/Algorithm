#include<iostream>
#include<vector>

using namespace std;

int T,N;

void input(vector<int> &nums){
    cin>>N;
    
    int tmp;
    while(N--){
        cin>>tmp;
        nums.push_back(tmp);
    }
}

void solution(vector<int> &nums){
    long long ret=0;
    int maxn=0;
    for(int i=nums.size()-1;i>=0;--i){
        int num=nums[i];
        if(maxn>num)
            ret+=maxn-num;
        else
            maxn=num;
    }
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        vector<int> nums;
        input(nums);
        solution(nums);
    }

    return 0;
}