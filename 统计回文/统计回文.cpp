#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool iscircle(string s)
{
	string tmp=s;
	reverse(tmp.begin(), tmp.end());
	return tmp == s;
}


int main()
{
	string A, B;
	cin >> A >> B;
	int cnt = 0;
	int it = 0;
	while (it <A.size())
	{
		string tmp = A;
		tmp.insert(it, B.c_str());
		if (iscircle(tmp))
			cnt++;
		it++;
	}
    A+=B;
    if(iscircle(A))
        cnt++;
	cout << cnt << endl;
	return 0;
}