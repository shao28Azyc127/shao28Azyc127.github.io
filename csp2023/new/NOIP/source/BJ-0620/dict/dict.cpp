#include<iostream>
#include<cstdio>
#include<cstring>
#define SBT 1

using namespace std;


int n, m;
char s[3000][3001];
int main()
{
    void calc(void);

    memset(s, '\0', 3000 * 3001 * sizeof(char));

#if SBT
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
#endif // SBT

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    calc();

    return 0;
}

void calc()
{
    bool a = true;
    if (n == 1)
        cout << 1;
    else if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (s[i][0] > s[j][0])
                {
                    a = false;
                    cout << 0;
                    break;
                }
            }
            if (a) cout << 1;
            a = true;
        }
    }
    else if (m == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                //first character
                if (s[i][0] > s[j][0])
                    if (s[i][1] > s[j][0])
                        if (s[i][0] > s[j][1])
                        {
                            a = false;
                            cout << 0;
                            break;
                        }
                //second character
                if (s[i][1] > s[j][1])
                    if (s[i][0] > s[j][1])
                        if (s[i][1] > s[j][0])
                        {
                            a = false;
                            cout << 0;
                            break;
                        }
            }
            if (a) cout << 1;
            a = true;
        }
    }
    cout << endl;
}
