#include <bits/stdc++.h>
using namespace std;

int a[10][10];

int s[10];
int t[10];

bool chk()
{
    int cnt = 0;
    for(int i=1; i<=5; i++)
    {
        if(s[i] == t[i]) cnt ++;
    }
    if(cnt == 5) return false;
    if(cnt == 4) return true;
    if(cnt == 3)
    {
        for(int i=1; i<=4; i++)
        {
            if(s[i] != t[i] && s[i + 1] != t[i + 1])
            {
                if(s[i] - t[i] == s[i + 1] - t[i + 1] || s[i] - t[i] == s[i + 1] - t[i + 1] - 10 || s[i] - t[i] - 10 == s[i + 1] - t[i + 1]) return true;
                else return false;
            }
        }
    }
    return false;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=5; j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int m1=0; m1<=9; m1++)
    {
        for(int m2=0; m2<=9; m2++)
        {
            for(int m3=0; m3<=9; m3++)
            {
                for(int m4=0; m4<=9; m4++)
                {
                    for(int m5=0; m5<=9; m5++)
                    {
                        s[1] = m1;
                        s[2] = m2;
                        s[3] = m3;
                        s[4] = m4;
                        s[5] = m5;
                        bool flag = 1;
                        for(int i=1; i<=n; i++)
                        {
                            for(int j=1; j<=5; j++)
                            {
                                t[j] = a[i][j];
                            }
                            if(!chk()) flag = 0;
                        }
                        cnt += flag;
                        // if(flag) for(int i=1; i<=5; i++) cout << s[i];
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
