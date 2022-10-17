#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> nums;

void input(){
    cin>>N;
    nums.resize(N+5);

    fill(&nums[0],&nums[N+5],0);
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }

}

int two_or_three(int idx){
    int num=0;

    num=min(nums[idx],nums[idx+1]-nums[idx+2]);

    if(num <= 0)
        return 0;

    nums[idx]-=num;
    nums[idx+1]-=num;

    return num*5;
}

int three(int idx){
    int num=0;

    num=min(nums[idx],nums[idx+1]);
    num=min(num,nums[idx+2]);

    nums[idx]-=num;
    nums[idx+1]-=num;
    nums[idx+2]-=num;
    return num*7;
}

int two(int idx){
    int num=0;

    num=min(nums[idx],nums[idx+1]);

    nums[idx]-=num;
    nums[idx+1]-=num;

    return num*5;
}

void solution(){
    int ret=0;
    for(int i=0;i<N;i++){
        int num=0;

        ret+=two_or_three(i);
        ret+=three(i);
        ret+=two(i);

        ret+=nums[i]*3;
    }
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}