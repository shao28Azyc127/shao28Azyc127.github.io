#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    int c, n, m, q;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    if(c == 1)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        printf("%d",(x!=y));
        for(int i = 1; i <= q; i++)
        {
            int k1, k2;
            scanf("%d%d",&k1,&k2);
            for(int j = 1; j <= k1; j++)
            {
                int pos, val;
                scanf("%d%d",&pos,&val);
                if(pos == 1) x = val;
            }
            for(int j = 1; j <= k2; j++)
            {
                int pos, val;
                scanf("%d%d",&pos,&val);
                if(pos == 1) y = val;
            }
            printf("%d",(x!=y));
        }
        printf("\n");
    }
    return 0;
}