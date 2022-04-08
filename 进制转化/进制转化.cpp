class Solution {
public:
    /**
     * ����ת��
     * @param M int���� ��������
     * @param N int���� ת�����Ľ���
     * @return string�ַ���
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
        if (N <= 10)//���ÿ��Ǵ�д��ĸ
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