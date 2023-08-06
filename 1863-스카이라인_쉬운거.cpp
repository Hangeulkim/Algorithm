#include<iostream>
#include<stack>
#include<vector>

using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> structures;

void input(){
    int a;
    cin>>n;

    structures.resize(n);
    for(int i=0;i<n;++i){
        cin>>a>>structures[i];
    }
}

void solution(){
    //스택을 이용하여 높이만 비교, 현재 스택에 들어 있는 높이보다 높다면 제거 스택에 넣을 때는 cnt + 1
    int cnt = 0;
    stack<int> st;
    st.push(0);

    for(int i=0;i<n;++i){
        int num = structures[i];

        //높이가 동일한 경우 같은 건물 이므로 빼지 않는다.
        while(st.top() > num)
            st.pop();

        //높이가 달라진 경우 다른 건물이므로 cnt 증가 후 스택에 추가
        if(st.top() < num){
            st.push(num);
            ++cnt;
        }
    }

    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}