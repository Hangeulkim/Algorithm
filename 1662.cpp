#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int ans=0,leng=0;
string input;
int tmp=0,place=0;

vector<int> cnt;
int calc(int a){
    if(a<0) return 0;
    if(input[a]==')'){
        cnt.push_back(0);
        return calc(a-1)*(input[place-1]-'0')+calc(place-2);
    }
    else if(input[a]=='(') {
        tmp=cnt.back();
        cnt.pop_back();
        place=a;
        return tmp;
    }
    else {
        if(!cnt.empty()){
            cnt.back()++;
            return calc(a-1);
        }
        else return 1+calc(a-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    leng=input.length()-1;
    ans=calc(leng);

    cout<<ans<<'\n';
    return 0;
}
