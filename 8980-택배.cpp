#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct data{
    int start, end, cost;
}d;

int N,C;
int M;
vector<d> boxes;
int chk[2001];

bool op(d &a, d &b){
    if(a.end == b.end){
        return a.start < b.start;
    }
    return a.end < b.end;
}

void input(){
    int a,b,c;

    cin>>N>>C>>M;
    for(int i=0;i<M;++i){
        cin>>a>>b>>c;

        boxes.push_back({a,b,c});    
    }
}

void solution(){
    int answer = 0;
    sort(boxes.begin(), boxes.end(), op);

    for(int i=0;i<M;++i){
        int start = boxes[i].start;
        int end = boxes[i].end;
        int cost = boxes[i].cost;

        int maxnum = *max_element(&chk[start], &chk[end]);
        int num = min(cost, C-maxnum);

        for(int j=start;j<end;++j){
            chk[j] += num;
        }
        
        answer += num;
    }

    cout << answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}