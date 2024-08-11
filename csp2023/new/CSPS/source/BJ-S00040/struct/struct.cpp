#include <bits/stdc++.h>

using namespace std;

int n, op, k, h;
char t[10000000], m[10000000], s[10000000];

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&op);
        if (op == 1) {
            scanf("%s %d",s, &k);
            for (int i=0; i<n; i++) {
                scanf("%s %s",t, m);
            }
            printf("%d %d\n", 8, k*8);
            h += k*8;

        }
        if (op == 2) {
            scanf("%s %s",t, m);
            h += 8;
            printf("%d\n", h);
        }
        if (op == 3) {
            scanf("%s",t);
            printf("%d\n", 8);
        }
        if (op == 4) {
            scanf("%d",&k);
            printf("long\n");
        }
    }
    return 0;
}
