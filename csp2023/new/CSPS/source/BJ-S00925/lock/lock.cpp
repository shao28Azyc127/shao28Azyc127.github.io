#include <bits/stdc++.h>
using namespace std;
int n,a[15][15],f[15],now;
bool b[15];
int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d %d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
    memset(f,-1,sizeof(f));
    if (n==1)
        printf("%d",81);
    else {
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++) {
                now=0;
                for (int k=1;k<=5;k++)
                    if (a[i][k]==a[j][k]) {
                        b[k]=true;
                        now++;
                    }
                if (now==5)
                    continue;
                for (int k=1;k<=5;k++) {
                    if (b[k]==true) {
                        f[k]=a[i][k];
                        continue;
                    }
                    else
                        if (k<=3&&b[k]==false&&b[k+1]==true&&b[k+2]==false)
                            k=k+2;
                }
            }
        now=0;
        for (int i=1;i<=5;i++)
            if (f[i]==-1)
                now++;
        if (now==0)
            printf("%d",1);
        else if (now==1)
            printf("%d",10);
        else if (now==2)
            printf("%d",27);
        else if (now==3)
            printf("%d",45);
        else
            printf("%d",63);
    }
    return 0;
}
