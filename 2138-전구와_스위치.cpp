#include<iostream>
#include<algorithm>

using namespace std;

int N;
string now, result;

void input(){
    cin>>N>>now>>result;
}

//맨 앞부터 다른 경우 다음 위치의 버튼을 눌러가며 진행, 맨 마지막 원소로 최종 확인
int calc(string str){
    int cnt = 0;
    for(int i=0;i<str.length()-1;++i){
        if(str[i] != result[i]){
            for(int j=0;j<3;++j){
                if(i+j >= str.length())
                    continue;
                str[i+j] = str[i+j] == '0' ? '1' : '0';
            }
            ++cnt;
        }
    }

    //마지막 원소가 동일하면 true
    if(str.back() == result.back())
        return cnt;
    return 987'654'321;
}

void solution(){
    //처음 버튼을 누른 경우
    string copy = now;
    copy[0] = copy[0] == '0' ? '1' : '0';
    copy[1] = copy[1] == '0' ? '1' : '0';

    //처음 버튼을 누른 경우와 안누른 경우중 더 작은 값
    int ans = min(calc(copy)+1, calc(now));

    if(ans == 987'654'321)
        cout<<-1<<'\n';
    else
        cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}