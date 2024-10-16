#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int calcDigit(long long num)
{
    long long tmp = num;

    int cnt = 0;
    while (tmp)
    {
        tmp /= 10;
        ++cnt;
    }

    return cnt;
}

vector<int> calcLR(long long num, int d)
{
    int l = 0, r = 0;

    string str = to_string(num);

    for (int i = 0; i < d; ++i)
    {
        if (i < d / 2)
            l = l * 10 + str[i] - '0';
        else
            r = r * 10 + str[i] - '0';
    }

    vector<int> lr;

    lr.push_back(l);
    lr.push_back(r);

    return lr;
}

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q)
{
    bool eflag = false;
    for (; p <= q; ++p)
    {
        long long num = (long long)p * p;
        int d = calcDigit(num);

        vector<int> lr = calcLR(num, d);

        if (lr[0] + lr[1] == p)
        {
            cout << p << " ";
            eflag = true;
        }
    }

    if (!eflag)
        cout << "INVALID RANGE" << '\n';
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
