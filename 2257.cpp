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
    if(a>=leng) return 0;

    else if(input[a]==')'){
        tmp=cnt.back();
        cnt.pop_back();
        if(input[a+1]<='9'&&input[a+1]>='2'){
            place=a+1;
            if(!cnt.empty()){
                cnt.back()+=tmp*(input[a+1]-'0');
                return 0;
            }
            else return tmp*(input[a+1]-'0');
        }

        else{
            place=a;
            if(!cnt.empty()){
                cnt.back()+=tmp;
                return 0;
            }
            else return tmp;
        }
    }

    else if(input[a]=='('){
        if(input[a+1]==')') return calc(a+2);

        else{
            cnt.push_back(0);
            return calc(a+1)+calc(place+1);
        }
    }

    else{
        if(!cnt.empty()){
            if(input[a+1]>='2'&&input[a+1]<='9'){
                if(input[a]=='H') cnt.back()+=1*(input[a+1]-'0');
                else if(input[a]=='C') cnt.back()+=12*(input[a+1]-'0');
                else if(input[a]=='O') cnt.back()+=16*(input[a+1]-'0');

                return calc(a+2);
            }

            else{
                if(input[a]=='H') cnt.back()+=1;
                else if(input[a]=='C') cnt.back()+=12;
                else if(input[a]=='O') cnt.back()+=16;

                return calc(a+1);
            }
        }

        else{
            if(input[a+1]>='2'&&input[a+1]<='9'){
                if(input[a]=='H') return 1*(input[a+1]-'0')+calc(a+2);
                else if(input[a]=='C') return 12*(input[a+1]-'0')+calc(a+2);
                else if(input[a]=='O') return 16*(input[a+1]-'0')+calc(a+2);
        }

            else{
                if(input[a]=='H') return 1+calc(a+1);
                else if(input[a]=='C') return 12+calc(a+1);
                else if(input[a]=='O') return 16+calc(a+1);
            }

        }
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    leng=input.length();
    ans=calc(0);

    cout<<ans<<'\n';
    return 0;
}
