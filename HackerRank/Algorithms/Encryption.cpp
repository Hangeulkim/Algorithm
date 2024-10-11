#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s)
{
    int len = s.length();

    double key = sqrt(len);
    int down = floor(key);
    int up = ceil(key);

    if (down * up < len)
        down = up;

    string ret;
    for (int i = 0; i < up; ++i)
    {
        for (int j = 0; j < down; ++j)
        {
            if (i + j * up >= len)
                continue;
            ret.push_back(s[i + j * up]);
        }

        ret.push_back(' ');
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
