#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int chk[8][3][2]={
    {
        {0,0}, {1,0}, {2,0}
    },
    {
        {0,1}, {1,1}, {2,1}
    },
    {
        {0,2}, {1,2}, {2,2}
    },
    {
        {0,0}, {0,1}, {0,2}
    },
    {
        {1,0}, {1,1}, {1,2}
    },
    {
        {2,0}, {2,1}, {2,2}
    },
    {
        {0,0}, {1,1}, {2,2}
    },
    {
        {0,2}, {1,1}, {2,0}
    }
};

bool calc(string str){
    int xcnt=0, ocnt=0;

    for(int i=0;i<9;++i){
        if(str[i] == 'O')
            ++ocnt;
        else if(str[i] == 'X')
            ++xcnt;
    }

    int dif = xcnt - ocnt;
    if(dif < 0 || dif > 1)
        return false;

    bool xflag = false, oflag = false;
    for(int m=0;m<8;++m){
        if(
            str[chk[m][0][0]*3+chk[m][0][1]] == str[chk[m][1][0]*3+chk[m][1][1]] &&
            str[chk[m][1][0]*3+chk[m][1][1]] == str[chk[m][2][0]*3+chk[m][2][1]]
        ){
            if(str[chk[m][0][0]*3+chk[m][0][1]] == 'X')
                xflag=true;

            else if(str[chk[m][0][0]*3+chk[m][0][1]] == 'O')
                oflag=true;
        }
    }

    if((xflag && oflag) || ((!xflag && !oflag) && (xcnt+ocnt != 9)))
        return false;

    if((oflag && dif == 1) || (xflag && dif != 1))
        return false;
    return true;
}

void solution(){
    string input;

    while(true){
        cin>>input;

        if(input.compare("end") == 0)
            return;

        if(calc(input))
            cout<<"valid"<<'\n';
        else
            cout<<"invalid"<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}