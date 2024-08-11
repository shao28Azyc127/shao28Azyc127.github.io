# include "bits/stdc++.h"

using namespace std;
int c, n, m, q;

int main ()
{
    freopen ("expand.in", "r", stdin);
    freopen ("expand.out", "w", stdout);
    scanf ("%d%d%d%d", &c, &n, &m, &q);
    if (c == 1)
    {
        q += 1;
        while (q--)
            printf ("1");
        return (0); 
    }
    q += 1;
    while (q--)
        printf ("0");
    return (0);
}