#include <iostream>
using namespace std;

int cnt[100005], vis[9][100005];

int abs(int x) {
    if (x >= 0) return x%10;
    else return (x+10)%10;
}

int hash1(int a, int b, int c, int d, int e) {
    //if (a >= 10 || b >= 10 || c >= 10 || d >= 10 || e >= 10) printf("hash error! (+)\n");
    //if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0) printf("hash error! (-)\n");

    int res=0;
    res+=a*10000;
    res+=b*1000;
    res+=c*100;
    res+=d*10;
    res+=e;

    return res;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    int n, a, b, c, d, e, tmp;
    scanf("%d", &n);

    for (int j=1; j<=n; j++) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

        for (int i=1; i<=9; i++) {
            tmp=hash1(a, b, c, d, abs(e-i));
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, c, d, abs(e+i));
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, c, abs(d-i), e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, c, abs(d+i), e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, abs(c-i), d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, abs(c+i), d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, abs(b-i), c, d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, abs(b+i), c, d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(abs(a-i), b, c, d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(abs(a+i), b, c, d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;
        }

        for (int i=1; i<=9; i++) {
            tmp=hash1(abs(a-i), abs(b-i), c, d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(abs(a+i), abs(b+i), c, d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, abs(b-i), abs(c-i), d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, abs(b+i), abs(c+i), d, e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, abs(c-i), abs(d-i), e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, abs(c+i), abs(d+i), e);
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, c, abs(d-i), abs(e-i));
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;

            tmp=hash1(a, b, c, abs(d+i), abs(e+i));
            if (!vis[j][tmp]) cnt[tmp]++, vis[j][tmp]=1;
        }
    }

    int ans=0;
    for (int i=0; i<=99999; i++) {
        //printf("%d\n", cnt[i]);
        if (cnt[i] == n) {
            //printf("%d\n", i);
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
