#include <iostream>
#include <cstdio>
using namespace std;

int n, m, max1, max2;

struct Str
{
    int cnt[26];
    inline void read()
    {
        char c = getchar();
        while(c < 'a' || c > 'z')  c = getchar();
        while(c >= 'a' && c <= 'z')
        {
            cnt[c - 'a']++;
            c = getchar();
        }
    }
    inline int zheng(int x)
    {
        for(int i = 0; i < 26; i++)
        {
            x -= cnt[i];
            if(x < 0)  return i;
        }
        return -1;
    }
    inline int ni(int x)
    {
        for(int i = 25; i >= 0; i--)
        {
            x -= cnt[i];
            if(x < 0)  return i;
        }
        return -1;
    }
};
Str a[3005];

inline bool snn(Str x, Str y)
{
    // ni x > ni y
    //printf("snn\n");
    for(int i = 25; i >= 0; i--)
    {
        //printf("%d %d %d\n", i, x.cnt[i], y.cnt[i]);
        if(x.cnt[i] < y.cnt[i])  return true;
        if(x.cnt[i] > y.cnt[i])  return false;
    }
    return false;
}
inline bool szn(Str x, Str y)
{
    // zheng x < ni y
    //printf("szn\n");
    for(int i = 0; i < m; i++)
    {
        int xi = x.zheng(i), yi = y.ni(i);
        //printf("%d %d %d\n", i, xi, yi);
        if(xi < yi)  return true;
        if(xi > yi)  return false;
    }
    return false;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    scanf("%d%d", &n, &m);
    if(n == 1)
    {
        puts("1");
        return 0;
    }
    a[0].cnt[25] = 999999;
    for(int i = 1; i <= n; i++)
    {
        a[i].read();
        if(snn(a[i], a[max1]))
        {
            max2 = max1;
            max1 = i;
        }
        else if(snn(a[i], a[max2]))
        {
            max2 = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == max1)  printf("%d", szn(a[i], a[max2]));
        else  printf("%d", szn(a[i], a[max1]));
    }
    puts("");
    return 0;
}
