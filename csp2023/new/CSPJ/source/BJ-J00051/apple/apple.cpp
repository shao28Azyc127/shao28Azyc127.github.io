#include <bits/stdc++.h>

using namespace std;
int n, d, cnt, r, g;

int main()
{
    freopen("apple.in","r", stdin);
    freopen("apple.out","w", stdout);
    scanf("%d",&n);
    cnt = 1;

    while (n) {
        r = n % 3;
        g = (n-1)/ 3;
        if (d == 0 && r == 1) {
                d = cnt;

        }
        n -= g+1;
        cnt++;
    }
    printf("%d %d\n", cnt-1, d);

    return 0;
}

