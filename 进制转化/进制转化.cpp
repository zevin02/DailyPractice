class Solution {
public:
    /**
     * 进制转换
     * @param M int整型 给定整数
     * @param N int整型 转换到的进制
     * @return string字符串
     */

    char GetChar(int n)
    {
        char ch;
        switch (n)
        {

        case 10:
            ch = 'A';
            break;
        case 11:
            ch = 'B';
            break;
        case 12:
            ch = 'C';
            break;
        case 13:
            ch = 'D';
            break;
        case 14:
            ch = 'E';
            break;
        case 15:
            ch = 'F';
            break;

        }
        return ch;
    }
    string solve(int M, int N)
    {
        // write code here
        string s;
        int flag = 0;


        if (M < 0)
        {
            M = -M;
            flag = 1;
        }
        if (N <= 10)//不用考虑大写字母
        {

            while (M)
            {
                char ch = M % N + '0';
                s.insert(s.begin(), ch);
                M /= N;
            }

        }
        else if (N > 10)
        {

            while (M)
            {
                int n = M % N;
                if (n <= 9 && N >= 0)
                {
                    char ch = n + '0';
                    s.insert(s.begin(), ch);
                }
                else
                {

                    s.insert(s.begin(), GetChar(n));
                }
                M /= N;
            }

        }
        if (flag)
        {
            s.insert(s.begin(), '-');
        }
        return s;
    }

};