#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n)
{
    vector<int> ret;

    ret.push_back(1);

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < ret.size(); ++j)
        {
            ret[j] *= i;
        }

        for (int j = 0; j < ret.size(); ++j)
        {
            int idx = j;
            while (ret[idx] >= 10)
            {
                int num = ret[idx] / 10;
                ret[idx++] %= 10;

                if (idx == ret.size())
                    ret.push_back(num);
                else
                    ret[idx] += num;
            }
        }
    }

    for (int i = ret.size() - 1; i >= 0; --i)
    {
        cout << ret[i];
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
