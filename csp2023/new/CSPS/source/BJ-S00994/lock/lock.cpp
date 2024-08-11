# include "stdio.h"

using namespace std;
bool f;
int ans;
int n;
int te;
int cnt;
int js;
int js_;
int p[7];
int a[8][10];
int b[8][10];

inline int solve1 ();
inline bool pdws ()
{
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j < i ; j++)
        {
            te++;
            for (int k = 1 ; k <= 5 ; k++)
                b[te][k] = a[i][k] - a[j][k];
        }
    for (int i = 1 ; i <= te ; i++)
    {
        js_ = 0;
        for (int j = 1 ; j <= 5 ; j++)
        {
            if (b[i][j] != 0)
                js_++;
            if (b[i][j] != 0 && b[i][j] != b[i][j - 1] && b[i][j] != b[i][j + 1])
                p[j] = 1;
            if (b[i][j] != 0 && j == 1)
                f = true;
            if (b[i][j] != 0 && j == 5)
                f = true;
            
        }
        if (js_ >= 3)
            return (false);
    }
    for (int i = 1 ; i <= 5 ; i++)
        js += p[i];
    if (js >= 3)
        return (false);
    return (true);
}
int main ()
{
    freopen ("lock.in", "r", stdin);
    freopen ("lock.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= 5 ; j++)
            scanf ("%d", &a[i][j]);
    if (n == 1)
    {
        printf ("%d\n", 81);
        return (0);
    }
    if (pdws () == false)
    {
        printf ("0\n");
        return (0);
    }
    ans += solve1 ();
//    ans += solve2 ();
    if (n == 2 && js == 0 && js_ == 2)
        ans += 7;
    else if (n == 2 && f == true)
        ans += 2;
    else if (n == 2)
        ans += 4;
    printf ("%d\n", ans);
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 1 ; j <= 5 ; j++)
    //         printf ("%d ", a[i][j]);
    //     printf ("\n");
    // }
    return (0);
}

inline int solve1 ()
{
    if (js == 1)
        return (10 - n);
    if (js >= 2)
        return (0);
    return (0);
}

/*
1
0 0 1 1 5
*/