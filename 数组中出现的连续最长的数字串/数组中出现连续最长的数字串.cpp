#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isnumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}
bool cmp(string s1, string s2)
{
    if (s1.size() > s2.size())
        return true;
    else
        return false;
}
int main()
{
    vector<string> res;
    string src;
    cin >> src;
    auto it = src.begin();
    while (it != src.end())
    {
        if (isnumber(*it))
        {
            string s;
            while (isnumber(*it))
            {
                s += *it;
                it++;
            }
            res.push_back(s);
        }
        else
        {
            it++;
        }
    }
    sort(res.begin(), res.end(), cmp);
    cout << res[0] << endl;
    return 0;
}