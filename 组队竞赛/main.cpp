#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> res;
    res.resize(n);
    vector<int> num;
    int k=n*3;
    while(k--)
    {
    int tmp;
    cin>>tmp;
    num.push_back(tmp);
    }
    sort(num.begin(),num.end(),greater<int>());
     
    long long  ans=0;
    for(int i=0;i<n;i++)
    {
    ans+=num[2*i+1];
    }
        cout<<ans<<endl;
     
     
return 0;
}
