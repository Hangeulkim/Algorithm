#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

deque<int> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>tmp;
    for(int i=1;i<=tmp;i++) st.push_back(i);
    while(1){
        if(st.size()==1){
            cout<<st.front()<<'\n';
            break;
        } 
        st.pop_front();
        st.push_back(st.front());
        st.pop_front();
    }
    return 0;
}
