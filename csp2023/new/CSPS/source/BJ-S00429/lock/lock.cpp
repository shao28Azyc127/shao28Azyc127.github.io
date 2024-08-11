#include<bits/stdc++.h>
using namespace std;
int code[10],ans[100005],x[7];
inline int solve() {
    return x[1]*1e4+x[2]*1e3+x[3]*1e2+x[4]*10+x[5];
}
int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=5;j++) scanf("%d",&x[j]);
        code[i]=solve();
    }
    for (int i=1;i<=n;i++) {
        int m=code[i];
        for (int j=5;j>=1;j--) {
            x[j]=m%10;
            m/=10;
        }
        //cout<<solve();
        //ans[solve()]++;
        for (int j=1;j<=9;j++) {
            for (int l=1;l<=5;l++) {
                x[l]=(x[l]+j)%10;
                ans[solve()]++;//cout<<solve()<<' ';
                x[l]=(x[l]+10-j)%10;
            }
            for (int l=1;l<=4;l++) {
                x[l]=(x[l]+j)%10;
                x[l+1]=(x[l+1]+j)%10;
                ans[solve()]+=10;
                x[l]=(x[l]+10-j)%10;
                x[l+1]=(x[l+1]+10-j)%10;
            }
        }
    }
    int cnt=0;
    for (int i=1;i<=1e5;i++) {
        if (ans[i]==n || ans[i]==n*10) {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
