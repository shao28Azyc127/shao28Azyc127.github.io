#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10;

int n;
int cnt;
int s[6];
int U[10][6];
int D[10][6];
int S[10][6];

inline bool Do(int x1,int y1,int x2,int y2)
{
    while(x1 != x2)
    {
        x1++;
        y1++;
        if(x1 > 9)
            x1 = 0;
        if(y1 > 9)
            y1 = 0;
    }

    return x1 == x2 && y1 == y2;
}

inline bool Check()
{
    for(register int i = 1;i <= n;++i)
    {
        int t = 0;
        bool Same = true;
        for(register int j = 1;j <= 5;++j)
            if(S[i][j] != s[j])
                Same = false;
        if(Same)
            return false;
        for(register int j = 1;j <= 5;++j)
        {
            //cout << t << endl;
            if(S[i][j] == s[j])
                continue;
            else if(t == 0)
            {
                if(j == 5)
                    break;
                if(S[i][j + 1] == s[j + 1])
                    t = 1;
                else
                {
                    t = 1;
                    if(!Do(S[i][j],S[i][j + 1],s[j],s[j + 1]))
                        return false;
                    j++;
                }
            }
            else if(t == 1)
                return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin >> n;
    for(register int i = 1;i <= n;i++)
        for(register int j = 1;j <= 5;j++)
            cin >> S[i][j];
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    s[1] = 1,s[2] = 2,s[3] = 7,s[4] = 5,s[5] = 8;
    for(register int a = 0;a <= 9;++a)
    {
        for(register int b = 0;b <= 9;++b)
        {
            for(register int c = 0;c <= 9;++c)
            {
                for(register int d = 0;d <= 9;++d)
                {
                    for(register int e = 0;e <= 9;++e)
                    {
                        s[1] = a,s[2] = b,s[3] = c,s[4] = d,s[5] = e;
                        bool ans = false;
                        if(Check()) 
                            cnt++;//,cout << a << b << c << d << e << endl;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}