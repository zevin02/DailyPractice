#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int cnt = 0;
    int n;
    cin >> n;
    vector<int>arr;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] < arr[i + 1])
        {
            while (i + 1 < arr.size() && arr[i] <= arr[i + 1])
            {
                i++;
            }
            i++;
            cnt++;
        }
        else if (arr[i] == arr[i + 1])
        {
            i++;
        }
        else
        {
            while (i + 1 < arr.size() && arr[i] >= arr[i + 1])
            {
                i++;
            }
            i++;
            cnt++;
        }
    }
    std::cout << cnt << endl;
   
    return 0;
}