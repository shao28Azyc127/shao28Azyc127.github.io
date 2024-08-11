#include <bits/stdc++.h>
using namespace std;
int n,ans,m,p;
bool b;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while (n!=0) {
        p++;
        m=n/3;
        if (m*3<n)
            m++;
        if (1+(m-1)*3==n&&b==false) {
            ans=p;
            b=true;
        }
        n-=m;
    }
    printf("%d %d",p,ans);
    return 0;
}
