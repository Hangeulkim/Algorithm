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
    //������ �̿��Ͽ� ���̸� ��, ���� ���ÿ� ��� �ִ� ���̺��� ���ٸ� ���� ���ÿ� ���� ���� cnt + 1
    int cnt = 0;
    stack<int> st;
    st.push(0);

    for(int i=0;i<n;++i){
        int num = structures[i];

        //���̰� ������ ��� ���� �ǹ� �̹Ƿ� ���� �ʴ´�.
        while(st.top() > num)
            st.pop();

        //���̰� �޶��� ��� �ٸ� �ǹ��̹Ƿ� cnt ���� �� ���ÿ� �߰�
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