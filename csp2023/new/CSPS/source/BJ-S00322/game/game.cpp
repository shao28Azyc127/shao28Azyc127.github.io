#include<iostream>
#include<cstdio>
const int MAXL = 2 * 10e6 + 1;

using namespace std;


int n;
char s[MAXL];
char a[MAXL];
int t = 0;
long long ans = 0;
int main()
{
    /*
     *     @@@@@@@@@@@@@@@      @@@@@                 @@@@@@@@@@@@@@@@@@@@@@@@             @@@@@             @@@@@@@@@@@@@@@@@@@@@@@@
     *     @@@@@@@@@@@@@@@      @@@@@                 @@@@@@@@@@@@@@@@@@@@@@@@             @@@@@             @@@@@@@@@@@@@@@@@@@@@@@@
     *               @@@@@      @@@@@                           @@@@@                  @@@@@   @@@@@                  @@@@@
     *               @@@@@      @@@@@                           @@@@@                  @@@@@   @@@@@                  @@@@@
     *               @@@@@      @@@@@                           @@@@@              @@@@@           @@@@@              @@@@@
     *     @@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@                @@@@@              @@@@@           @@@@@              @@@@@
     *     @@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@                @@@@@              @@@@@           @@@@@              @@@@@
     *               @@@@@      @@@@@      @@@@@                @@@@@              @@@@@@@@@@@@@@@@@@@@@              @@@@@
     *               @@@@@      @@@@@      @@@@@                @@@@@              @@@@@@@@@@@@@@@@@@@@@              @@@@@
     *               @@@@@      @@@@@      @@@@@                @@@@@              @@@@@           @@@@@              @@@@@               55555555555~
     *     @@@@@@@@@@@@@@@      @@@@@      @@@@@                @@@@@              @@@@@           @@@@@              @@@@@
     *     @@@@@@@@@@@@@@@      @@@@@      @@@@@                @@@@@              @@@@@           @@@@@              @@@@@
     *
     */
    void calc(void);
    void print(void);

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    calc();
    print();

    return 0;
}


void calc()
{
    for (int i = 0; i < n; i++)
    {
        a[t] = s[i];
        if (t > 0)
        {
            if (a[t] == a[t - 1])
            {
                cout << a[t] << ' ' << a[t-1] << endl;
                ans++;
                t -= 2;
            }
        }
        t++;
    }
    if (t == 0)
        ans ++;
}


/*
void calc()
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        t = 0;
        m = i;
        for (int j = i; j < n; j++)
        {
            a[t] = s[m];
            a[t++] = s[m++];
            //t must more than 0
            if (a[t] == a[t - 1])
            {
                ans++;
            }
        }
    }
}
*/

/*
int countn(int b, int e)
{
    int ret = 0;
    ret += e - b;
    if ((e - b) % 2 == 1)
        ret++;
    return ret;
}

void ch(int b, int e)
{
    int t;
    if ((e - b) % 2 == 1)
    {
        t = b;
        for (int i = e + 1; i < n; i++)
        {
            s[t++] = s[i];
        }
    }
    else
    {
        t = b + 1;
        for (int i = e + 1; i < n; i++)
        {
            s[t++] = s[i];
        }
    }
    n -= e - b + 1;
}

void calc()
{
    int b = 0, e = 0;
    bool founded = true;
    while(founded)
    {
        founded = false;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                if (s[i - 1] == s[b])
                {
                    e = i - 1;
                    ans += countn(b, e);
                    ch(b, e);
                    founded = true;
                    break;
                }
                else
                {
                    b = i;
                }
            }
        }
    }
    if (n <= 0)
    {
        ans++;
    }
}
*/
void print()
{
    cout << ans << endl;
}
