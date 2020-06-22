#include <bits/stdc++.h>
using namespace std;

int N,K,tmp,tmp1;
vector<int> cutting;
vector<int> input;
int sum=0;

bool all_chk(int num){
    for(auto it : cutting){
        if(it==num) return false;
    }
    return true;
}

void find(){
    int l=1,r=1;
    int max_l,max_r=0;
    int max_num=0;
    for(l=1;l<=N-1;l++){
        for(r=l+1;r<=N;r++){
            int tmp=input[r]-input[l];
            if(max_num<tmp&&all_chk(r)){
                max_l=l;
                max_r=r;
                max_num=tmp;
            }
        }
    }
    cutting.push_back(max_r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>N>>K;
    input.push_back(0);

	for(int i=1;i<=N;i++){
		cin>>tmp;
		input.push_back(tmp);
	}

    K-=1;
    while(K--){
        find();
        sort(cutting.begin(),cutting.end());
    }
    cutting.push_back(N);

    tmp=1;
    for(int i=0;i<cutting.size()-1;i++){
        sum+=input[cutting[i]]-input[tmp];
        tmp=cutting[i]+1;
    }
    cout<<sum;

	return 0;
}
