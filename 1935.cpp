#include<iostream>
#include<string>
#include<cstdio>
#include<vector>

using namespace std;

long double num[256];
int tmp,tmpnum;
string input;
long double result=0;
vector<long double> cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tmp>>input;
    for(int i=0;i<tmp;i++){
        cin>>tmpnum;
        num['A'+i]=tmpnum;
    }
    for(int i=0;i<input.length();i++){
        switch(input[i]){
            case '+':
            {
                long double tmpn1=cnt[cnt.size()-2];
                long double tmpn2=cnt[cnt.size()-1];
                cnt.pop_back();
                cnt.pop_back();
                cnt.push_back(tmpn1+tmpn2);
            }
                break;
            case '-':
            {
                long double tmpn1=cnt[cnt.size()-2];
                long double tmpn2=cnt[cnt.size()-1];
                cnt.pop_back();
                cnt.pop_back();
                cnt.push_back(tmpn1-tmpn2);
            }
                break;
            case '*':
            {
                long double tmpn1=cnt[cnt.size()-2];
                long double tmpn2=cnt[cnt.size()-1];
                cnt.pop_back();
                cnt.pop_back();
                cnt.push_back(tmpn1*tmpn2);
            }
                break;
            case '/':
            {
                long double tmpn1=cnt[cnt.size()-2];
                long double tmpn2=cnt[cnt.size()-1];
                cnt.pop_back();
                cnt.pop_back();
                cnt.push_back(tmpn1/tmpn2);
            }
                break;
            default:
                cnt.push_back(num[input[i]]);
                break;
        }
    }

    result=cnt.back();
    cout<<fixed;
    cout.precision(2);
    cout<<result<<'\n';
    return 0;
}
