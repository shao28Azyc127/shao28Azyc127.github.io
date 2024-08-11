#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int from[N];
char val[N];
// int find(int x, bool neg)
// {
//     printf("find(%d)\n", x);
//     if (from[x] == x) return x;
//     int ffromx=find(from[x], 0);

//     return from[x] = ffromx;
// }
void init(int n)
{
    for (int i = 1; i <= n; i++) from[i]=i;
    memset(val, 0, sizeof(val));
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    if (c == 3 || c == 4)
    {
        while (t--)
        {
            int n, m;
            scanf("%d%d", &n, &m);
            while (m--)
            {
                char v;
                int i, j;
                scanf(" %c%d", &v, &i);
                switch(v)
                {
                    case 'T':
                    case 'F':
                    case 'U':
                        {val[i] = v;break;}
                    
                }
            }
            // todo
            int cnt=0;
            for (int i = 1; i <= n; i++)
            {
                if (val[i] == 'U') cnt++;
            }
            printf("%d\n", cnt);
        }
        return 0;
    }
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        while (m--)
        {
            char v;
            int i, j;
            scanf(" %c%d", &v, &i);
            switch(v)
            {
                case 'T':
                case 'F': break;
                case 'U':
                    {val[i] = 'U';break;}
                case '+':
                {
                    scanf("%d", &j);
                    from[i] = from[j];
                    break;
                }
                case '-':
                {
                    scanf("%d", &j);
                    from[i] = (-from[j]);
                    break;
                }
            }
        }
        int cnt=0;
        for (int i = 1; i <= n; i++)
        {
            if (i == -from[i]) val[i] = 'U';
        }
        for (int i = 1; i <= n; i++) if (val[abs(from[i])] == 'U') cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}