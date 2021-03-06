#include<bits/stdc++.h>

using namespace std;

vector<int> input(30);

int mk[6][6][4]={
    {
        {13,14,15,16},
        {17,18,19,20},
        {1,3,6,8},
        {5,7,10,12},
        {2,4,22,24},
        {9,11,21,23}
    },
    {
        {13,14,15,16},
        {17,18,19,20},
        {1,3,21,23},
        {2,4,5,7},
        {6,8,9,11},
        {10,12,22,24}
    },
    {
        {1,2,3,4},
        {9,10,11,12},
        {5,6,19,20},
        {13,14,7,8},
        {17,18,23,24},
        {15,16,21,22}
    },
    {
        {1,2,3,4},
        {9,10,11,12},
        {5,6,15,16},
        {17,18,7,8},
        {13,14,23,24},
        {19,20,21,22}
    },
    {
        {5,6,7,8},
        {21,22,23,24},
        {1,2,17,19},
        {13,15,3,4},
        {11,12,14,16},
        {9,10,18,20}
    },
    {
        {5,6,7,8},
        {21,22,23,24},
        {1,2,14,16},
        {13,15,9,10},
        {11,12,17,19},
        {3,4,18,20}
    }
};

int run_cube(){
    bool flag=false;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(input[mk[i][j][0]]!=input[mk[i][j][1]]||input[mk[i][j][1]]!=input[mk[i][j][2]]||input[mk[i][j][2]]!=input[mk[i][j][3]]){
                flag=false;
                break;
            }
            flag=true;
        }

        if(flag) break;
    }

    if(flag)
        return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=24;i++){
        cin>>input[i];
    }

    cout<<run_cube();

    return 0;
}
