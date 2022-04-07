#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int main()
{
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    size_t pos = s.find(" ");
    reverse(s.begin(), s.begin() + pos);
    size_t prepos;
    while (pos != string::npos)
    {
        prepos = pos;
        pos = s.find(" ", prepos + 1);
        if (pos == string::npos)
            reverse(s.begin() + prepos + 1, s.end());
        else
            reverse(s.begin() + prepos + 1, s.begin() + pos);
    }

    cout << s << endl;
    return 0;
}