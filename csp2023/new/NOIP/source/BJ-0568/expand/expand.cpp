#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+5;
int x[inf],y[inf],a[inf],b[inf],n,m;
bool dp[2005][2005];
inline void getans() {
    bool p=0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    if (x[1]>y[1]) {
        p=1;
        swap(x,y);
        swap(m,n);
    }
    else if (x[1]==y[1]) {
        printf("0");
        return ;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (x[i]<y[j]) {
                dp[i][j]|=dp[i-1][j-1]|dp[i][j-1]|dp[i-1][j];
            }
        }
    }
    if (dp[n][m]) printf("1");
    else printf("0");
    if (p) {
        swap(x,y);
        swap(m,n);
    }
    return ;
}
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,q;
    scanf("%d %d %d %d",&c,&n,&m,&q);
    if (c<=7) {
        for (int i=1;i<=n;i++) {
            scanf("%d",&x[i]);
            a[i]=x[i];
        }
        for (int j=1;j<=m;j++) {
            b[j]=y[j];
            scanf("%d",&y[j]);
        }
        getans();
        while (q--) {
            for (int i=1;i<=n;i++) {
                x[i]=a[i];
            }
            for (int i=1;i<=m;i++) {
                y[i]=b[i];
            }
            int kx,ky;
            scanf("%d %d",&kx,&ky);
            for (int i=1;i<=kx;i++) {
                int aa,bb;
                scanf("%d %d",&aa,&bb);
                x[aa]=bb;
            }
            for (int i=1;i<=ky;i++) {
                int aa,bb;
                scanf("%d %d",&aa,&bb);
                y[aa]=bb;
            }
            getans();
        }
    }
    return 0;
}
