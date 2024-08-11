/*
小 Y 的桌子上放着 n 个苹果从左到右排成一列,编号为从 1 到 n。
小苞是小 Y 的好朋友,每天她都会从中拿走一些苹果。
每天在拿的时候,小苞都是从左侧第 1 个苹果开始、每隔 2 个苹果拿走 1 个苹果。
随后小苞会将剩下的苹果按原先的顺序重新排成一列。
小苞想知道,多少天能拿完所有的苹果,而编号为 n 的苹果是在第几天被拿走的?

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
