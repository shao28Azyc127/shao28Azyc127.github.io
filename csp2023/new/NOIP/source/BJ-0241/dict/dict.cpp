// 10pts + 30pts + 30pts + 20pts = 90pts
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
char a[3005][3005];
int cnt[3005][30];
void n1()   // 10pts
{
    cout << 1;
}
void m1()   // 30pts    dict2   AC
{
    for(int i = 1; i <= n; i++)
    {
        bool flag = true;
        for(int j = 1; j <= n && flag; j++)
            if(i != j && a[i][1] > a[j][1]) flag = false;
        cout << flag;
    }
}
void m2()   // 30pts    dict3   AC
{
    for(int i = 1; i <= n; i++)
    {
        bool flag = true;
        char a1 = min(a[i][1], a[i][2]);
        char a2 = max(a[i][1], a[i][2]);
        for(int j = 1; j <= n && flag; j++)
            if(i != j)
            {
                char b1 = max(a[j][1], a[j][2]);
                char b2 = min(a[j][1], a[j][2]);
                if(b1 < a1 || (b1 == a1 && b2 < a2)) flag = false;
            }
        cout << flag;
    }
}
bool check(int x, int y)    // i是否能通过排序小于j
{
    int s1[3005], s2[3005];
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 26; i++)
        for(int j = 1; j <= cnt[x][i]; j++) s1[++cnt1] = i;

    for(int i = 25; i >= 0; i--)
        for(int j = 1; j <= cnt[y][i]; j++) s2[++cnt2] = i;
//cout << "\ncheck " << x << ' ' << y <<endl;
//cout << x << ' '; for(int i = 1; i <= cnt1; i++) cout << char(s1[i] + 'a') << " "; cout << endl;
//cout << y << ' '; for(int i = 1; i <= cnt2; i++) cout << char(s2[i] + 'a') << " "; cout << endl;
    bool ret1 = true, ret2 = true;
    for(int i = 1; i <= m; i++)
        if(s1[i] < s2[i]) return true;
        else if(s1[i] > s2[i]) return false;
    return false;
}
void n300()     // 20pts    dict1 & dict2 & dict3   AC
{
    for(int i = 1; i <= n; i++)
    {
        bool flag = true;
        for(int j = 1; j <= n && flag; j++)
            if(i != j) flag &= check(i, j);
        cout << flag;
    }
}
int main()
{
    // dict1
    // dict2    AC  +30pts  AC
    // dict3    AC  +30pts  AC
    // dict4    TLE -10pts
    //freopen("dict4.in", "r", stdin);
    //freopen("dict1.out", "w", stdout);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            cnt[i][a[i][j] - 'a']++;
        }
    if(n == 1) n1();
    else if(m == 1) m1();
    else if(m == 2) m2();
    else n300();
    /*
    unsigned long long ck = 0;
    for(int i = 1; i <= 300; i++)
    {
        if(ck < 0) cout << -1 << endl;
        ck = ck * 26 + 25;
        cout << i << ' ' << ck << endl;
    }
    cout << endl << ck << endl;*/
    return 0;
}
