#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b)
{
    int bugs[31] = {
        0,
    };

    // count empty cells and bugs
    for (int i = 0; i < b.length(); ++i)
    {
        if (b[i] == '_')
            ++bugs[30];
        else
            ++bugs[b[i] - 'A'];
    }

    // check bugs are all happy when ZERO empty cell
    if (!bugs[30])
    {
        for (int i = 0; i < b.length(); ++i)
        {
            bool pflag = false;

            int prev = i - 1;
            int next = i + 1;

            if (prev >= 0 && b[i] == b[prev])
            {
                pflag = true;
            }

            if (next < b.length() && b[i] == b[next])
            {
                pflag = true;
            }

            if (!pflag)
                return "NO";
        }
    }
    for (int i = 0; i <= 'Z' - 'A'; ++i)
    {
        // pass when zero bugs
        if (!bugs[i])
            continue;

        if (bugs[i] == 1)
            return "NO";
    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

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
