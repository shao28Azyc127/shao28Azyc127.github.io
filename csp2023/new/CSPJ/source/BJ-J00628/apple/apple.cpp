/*
С Y �������Ϸ��� n ��ƻ���������ų�һ��,���Ϊ�� 1 �� n��
С����С Y �ĺ�����,ÿ���������������һЩƻ����
ÿ�����õ�ʱ��,С�����Ǵ����� 1 ��ƻ����ʼ��ÿ�� 2 ��ƻ������ 1 ��ƻ����
���С���Ὣʣ�µ�ƻ����ԭ�ȵ�˳�������ų�һ�С�
С����֪��,���������������е�ƻ��,�����Ϊ n ��ƻ�����ڵڼ��챻���ߵ�?

1 2 3 4 5 6 7 8
~ 2 3 ~ 5 6 ~ 8
  ~ 3   5 ~   8
    ~   5     8
        ~     8
              ~
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{

    ifstream cin("apple.in", ios::in);
    ofstream cout("apple.out", ios::out);

    int n;
    cin >> n;
    int flag[n], n_time, day = 1;
    for(int i = 0;i < n;i++) flag[i] = 0;
    int sum = n;
    while(sum > 0)
    {
        int now = 0;
        for(int i = 0;i < n;i++)
        {
            if(flag[i] == 0)
            {
                if(now % 3 == 0)
                {
                    flag[i] = 1;
                    sum--;
                    if(i == n - 1) n_time = day;
                    now += 1;
                }
                else
                {
                    now += 1;
                }
            }
        }
        day++;
    }
    cout << day - 1 << ' ' << n_time << endl;
    return 0;
}
