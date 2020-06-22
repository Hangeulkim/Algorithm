#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct data{
    int dshow;//나온 횟수
    int dnum;//메시지 값
};

bool cmp(const data& a, const data& b){
    return a.dshow > b.dshow;
}

vector<data> input;

int main(){
    int N=0,C=0;
    scanf("%d %d",&N,&C);

    int temp=0;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        int dflag=-100;
        if(!input.empty()){
            int size=input.size();
            for(int i=0;i<size;i++){
                if(input[i].dnum==temp)
                    dflag=i;
            }
        }
        if(dflag==-100){
            data d;
            d.dshow=1;
            d.dnum=temp;
            input.push_back(d);
        }
        else{
            input[dflag].dshow++;
        }
    }
    stable_sort(input.begin(),input.end(),cmp);
    for(auto it : input){
        for(int i=0;i<it.dshow;i++){
            printf("%d ",it.dnum);
        }
    }

    return 0;
}
