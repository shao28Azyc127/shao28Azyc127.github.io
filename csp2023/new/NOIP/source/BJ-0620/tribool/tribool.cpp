#include<iostream>
#include<cstdio>
#include<cstring>
#define V_U 'U'
#define V_T 'T'
#define V_F 'F'
#define S_P '+'
#define S_N '-'
#define is_valuen(x) (((x) == V_U) || ((x) == V_T) || ((x) == V_F))
#define SBT 1

using namespace std;


struct Tribool
{
    int mac;
    int eq; // one of the macs
    bool rs; // 0 -> neg 1 -> pos
    char value;
    bool getter;
    void rsetter(int m, bool s)
    {
        eq = m;
        rs = s;
        getter = false;
    }
    void vsetter(char v)
    {
        value = v;
        getter = true;
    }
};
int ans;
int c, t; // test num
char v;
int n, m;
int xi, xj;
char s[100001];
Tribool b[100001];
//20...
int main()
{
    void search(int);
#if SBT
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
#endif // SBT
    cin >> c >> t;
    for (int i = 1; i < 10001; i++)
    {
        b[i].mac = i;
    }/*
    if (c == 1)
    {
        for (int i = 0; i < t; i++)
        {
            cin >> n >> m;
            for (int j = 0; j < m; j++)
            {
                cin >> v;
                if (is_valuen(v))
                {
                    cin >> xi;
                    b[xi].vsetter(v);
                }
                else if (v == S_P)
                {
                    cin >> xi >> xj;
                    b[xi].rsetter(xj, true);
                }
                else
                {
                    cin >> xi >> xj;
                    b[xi].rsetter(xj, false);
                }
            }
            search(1);
        }
    }*/
    else if ((c == 3)||(c == 4)||(c == 1))
    {
        for (int i = 0; i < t; i++)
        {
            cin >> n >> m;
            for (int j = 0; j < m; j++)
            {
                cin >> v >> xi;
                s[xi] = v;
            }
            for (int i = 1; i <= n; i++)
            {
                if (s[i] == V_U)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    else
    {

    }


    return 0;
}

void search(int k)
{
    int ans = 0, res = 0;
    if (k == n)
    {
        if (res > ans)
            ans = res;
    }
    for (int i = k; i < n; i++)
    {

    }
}
