#include<iostream>
#include<string>
using  namespace std;
int main()
{
    string s1;
    string s2;
    getline(cin, s1);
    cin >> s2;
    auto it2 = s2.begin();
    while (it2 != s2.end())
    {
        auto it1 = s1.begin();
        while (it1 != s1.end())
        {
            if (*it1 == *it2)
            {
                s1.erase(it1);
                
            }
            else
            {
                it1++;
            }
        }
        it2++;
    }
    cout << s1 << endl;
    return 0;
}