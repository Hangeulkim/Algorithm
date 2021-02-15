#include<bits/stdc++.h>

using namespace std;

int N;
int tc;

vector<char> Cube[7];
char m[2];

void move_cube(){
    char Tmp[3];
    int where;

    if (m[0] == 'U') where=1;
    else if (m[0] == 'D') where=2;
    else if (m[0] == 'F') where=3;
    else if (m[0] == 'B') where=4;
    else if (m[0] == 'L') where=5;
    else if (m[0] == 'R') where=6;

    if (where == 1)
    {
        if (m[1] == '+')
        {
            Tmp[0] = Cube[6][0];
            Tmp[1] = Cube[6][1];
            Tmp[2] = Cube[6][2];

            Cube[6][0] = Cube[4][0];
            Cube[6][1] = Cube[4][1];
            Cube[6][2] = Cube[4][2];

            Cube[4][0] = Cube[5][0];
            Cube[4][1] = Cube[5][1];
            Cube[4][2] = Cube[5][2];

            Cube[5][0] = Cube[3][0];
            Cube[5][1] = Cube[3][1];
            Cube[5][2] = Cube[3][2];

            Cube[3][0] = Tmp[0];
            Cube[3][1] = Tmp[1];
            Cube[3][2] = Tmp[2];
        }
        else
        {
            Tmp[0] = Cube[6][0];
            Tmp[1] = Cube[6][1];
            Tmp[2] = Cube[6][2];

            Cube[6][0] = Cube[3][0];
            Cube[6][1] = Cube[3][1];
            Cube[6][2] = Cube[3][2];

            Cube[3][0] = Cube[5][0];
            Cube[3][1] = Cube[5][1];
            Cube[3][2] = Cube[5][2];

            Cube[5][0] = Cube[4][0];
            Cube[5][1] = Cube[4][1];
            Cube[5][2] = Cube[4][2];

            Cube[4][0] = Tmp[0];
            Cube[4][1] = Tmp[1];
            Cube[4][2] = Tmp[2];
        }
    }
    else if (where == 2)
    {
        if (m[1] == '+')
        {
            Tmp[0] = Cube[3][6];
            Tmp[1] = Cube[3][7];
            Tmp[2] = Cube[3][8];

            Cube[3][6] = Cube[5][6];
            Cube[3][7] = Cube[5][7];
            Cube[3][8] = Cube[5][8];

            Cube[5][6] = Cube[4][6];
            Cube[5][7] = Cube[4][7];
            Cube[5][8] = Cube[4][8];

            Cube[4][6] = Cube[6][6];
            Cube[4][7] = Cube[6][7];
            Cube[4][8] = Cube[6][8];

            Cube[6][6] = Tmp[0];
            Cube[6][7] = Tmp[1];
            Cube[6][8] = Tmp[2];
        }
        else
        {
            Tmp[0] = Cube[3][6];
            Tmp[1] = Cube[3][7];
            Tmp[2] = Cube[3][8];

            Cube[3][6] = Cube[6][6];
            Cube[3][7] = Cube[6][7];
            Cube[3][8] = Cube[6][8];

            Cube[6][6] = Cube[4][6];
            Cube[6][7] = Cube[4][7];
            Cube[6][8] = Cube[4][8];

            Cube[4][6] = Cube[5][6];
            Cube[4][7] = Cube[5][7];
            Cube[4][8] = Cube[5][8];

            Cube[5][6] = Tmp[0];
            Cube[5][7] = Tmp[1];
            Cube[5][8] = Tmp[2];
        }
    }
    else if (where == 3)
    {
        if (m[1] == '+')
        {
            Tmp[0] = Cube[1][6];
            Tmp[1] = Cube[1][7];
            Tmp[2] = Cube[1][8];

            Cube[1][6] = Cube[5][8];
            Cube[1][7] = Cube[5][5];
            Cube[1][8] = Cube[5][2];

            Cube[5][8] = Cube[2][2];
            Cube[5][5] = Cube[2][1];
            Cube[5][2] = Cube[2][0];

            Cube[2][2] = Cube[6][0];
            Cube[2][1] = Cube[6][3];
            Cube[2][0] = Cube[6][6];

            Cube[6][0] = Tmp[0];
            Cube[6][3] = Tmp[1];
            Cube[6][6] = Tmp[2];
        }
        else
        {
            Tmp[0] = Cube[1][6];
            Tmp[1] = Cube[1][7];
            Tmp[2] = Cube[1][8];

            Cube[1][6] = Cube[6][0];
            Cube[1][7] = Cube[6][3];
            Cube[1][8] = Cube[6][6];

            Cube[6][0] = Cube[2][2];
            Cube[6][3] = Cube[2][1];
            Cube[6][6] = Cube[2][0];

            Cube[2][2] = Cube[5][8];
            Cube[2][1] = Cube[5][5];
            Cube[2][0] = Cube[5][2];

            Cube[5][8] = Tmp[0];
            Cube[5][5] = Tmp[1];
            Cube[5][2] = Tmp[2];
        }
    }
    else if (where == 4)
    {
        if (m[1] == '+')
        {
            Tmp[0] = Cube[1][0];
            Tmp[1] = Cube[1][1];
            Tmp[2] = Cube[1][2];

            Cube[1][0] = Cube[6][2];
            Cube[1][1] = Cube[6][5];
            Cube[1][2] = Cube[6][8];

            Cube[6][2] = Cube[2][8];
            Cube[6][5] = Cube[2][7];
            Cube[6][8] = Cube[2][6];

            Cube[2][8] = Cube[5][6];
            Cube[2][7] = Cube[5][3];
            Cube[2][6] = Cube[5][0];

            Cube[5][6] = Tmp[0];
            Cube[5][3] = Tmp[1];
            Cube[5][0] = Tmp[2];
        }
        else
        {
            Tmp[0] = Cube[1][0];
            Tmp[1] = Cube[1][1];
            Tmp[2] = Cube[1][2];

            Cube[1][0] = Cube[5][6];
            Cube[1][1] = Cube[5][3];
            Cube[1][2] = Cube[5][0];

            Cube[5][6] = Cube[2][8];
            Cube[5][3] = Cube[2][7];
            Cube[5][0] = Cube[2][6];

            Cube[2][8] = Cube[6][2];
            Cube[2][7] = Cube[6][5];
            Cube[2][6] = Cube[6][8];

            Cube[6][2] = Tmp[0];
            Cube[6][5] = Tmp[1];
            Cube[6][8] = Tmp[2];
        }
    }
    else if (where == 5)
    {
        if (m[1] == '+')
        {

            Tmp[0] = Cube[3][0];
            Tmp[1] = Cube[3][3];
            Tmp[2] = Cube[3][6];

            Cube[3][0] = Cube[1][0];
            Cube[3][3] = Cube[1][3];
            Cube[3][6] = Cube[1][6];

            Cube[1][0] = Cube[4][8];
            Cube[1][3] = Cube[4][5];
            Cube[1][6] = Cube[4][2];

            Cube[4][8] = Cube[2][0];
            Cube[4][5] = Cube[2][3];
            Cube[4][2] = Cube[2][6];

            Cube[2][0] = Tmp[0];
            Cube[2][3] = Tmp[1];
            Cube[2][6] = Tmp[2];
        }
        else
        {
            Tmp[0] = Cube[3][0];
            Tmp[1] = Cube[3][3];
            Tmp[2] = Cube[3][6];

            Cube[3][0] = Cube[2][0];
            Cube[3][3] = Cube[2][3];
            Cube[3][6] = Cube[2][6];

            Cube[2][0] = Cube[4][8];
            Cube[2][3] = Cube[4][5];
            Cube[2][6] = Cube[4][2];

            Cube[4][8] = Cube[1][0];
            Cube[4][5] = Cube[1][3];
            Cube[4][2] = Cube[1][6];

            Cube[1][0] = Tmp[0];
            Cube[1][3] = Tmp[1];
            Cube[1][6] = Tmp[2];
        }
    }
    else if (where == 6)
    {
        if (m[1] == '+')
        {
            Tmp[0] = Cube[3][2];
            Tmp[1] = Cube[3][5];
            Tmp[2] = Cube[3][8];

            Cube[3][2] = Cube[2][2];
            Cube[3][5] = Cube[2][5];
            Cube[3][8] = Cube[2][8];

            Cube[2][2] = Cube[4][6];
            Cube[2][5] = Cube[4][3];
            Cube[2][8] = Cube[4][0];

            Cube[4][6] = Cube[1][2];
            Cube[4][3] = Cube[1][5];
            Cube[4][0] = Cube[1][8];

            Cube[1][2] = Tmp[0];
            Cube[1][5] = Tmp[1];
            Cube[1][8] = Tmp[2];
        }
        else
        {
            Tmp[0] = Cube[3][2];
            Tmp[1] = Cube[3][5];
            Tmp[2] = Cube[3][8];

            Cube[3][2] = Cube[1][2];
            Cube[3][5] = Cube[1][5];
            Cube[3][8] = Cube[1][8];

            Cube[1][2] = Cube[4][6];
            Cube[1][5] = Cube[4][3];
            Cube[1][8] = Cube[4][0];

            Cube[4][6] = Cube[2][2];
            Cube[4][3] = Cube[2][5];
            Cube[4][0] = Cube[2][8];

            Cube[2][2] = Tmp[0];
            Cube[2][5] = Tmp[1];
            Cube[2][8] = Tmp[2];
        }
    }

    if (m[1] == '+')
    {
        Tmp[0] = Cube[where][0];
        Tmp[1] = Cube[where][1];

        Cube[where][0] = Cube[where][6];
        Cube[where][6] = Cube[where][8];
        Cube[where][8] = Cube[where][2];
        Cube[where][2] = Tmp[0];


        Cube[where][1] = Cube[where][3];
        Cube[where][3] = Cube[where][7];
        Cube[where][7] = Cube[where][5];
        Cube[where][5] = Tmp[1];
    }
    else if (m[1] == '-')
    {
        Tmp[0] = Cube[where][0];
        Tmp[1] = Cube[where][1];

        Cube[where][0] = Cube[where][2];
        Cube[where][2] = Cube[where][8];
        Cube[where][8] = Cube[where][6];
        Cube[where][6] = Tmp[0];

        Cube[where][1] = Cube[where][5];
        Cube[where][5] = Cube[where][7];
        Cube[where][7] = Cube[where][3];
        Cube[where][3] = Tmp[1];
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    while(N--){
        for (int i = 0; i < 7; i++) Cube[i].clear();

        for (int i = 0; i < 9; i++)
        {
            Cube[1].push_back('w');
            Cube[2].push_back('y');
            Cube[3].push_back('r');
            Cube[4].push_back('o');
            Cube[5].push_back('g');
            Cube[6].push_back('b');
        }

        cin>>tc;
        while(tc--){
            cin>>m[0]>>m[1];

            move_cube();
        }

        for (int i = 0; i < 9; i++)
        {
            cout << Cube[1][i];

            if (i%3==2)
            {
                cout << '\n';
            }
        }
    }

    return 0;
}
