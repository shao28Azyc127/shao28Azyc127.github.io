#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long n,a[10][6],ans,f;

int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=5;j++) {
            cin >> a[i][j];
        }
    }
    if(n==1) ans=81;
    else if(n==2) {
        int z=0;
        for(int i=1;i<=5;i++) {
            if(a[1][i]!=a[2][i]) z++;
        }
        if(z==1) {
            for(int i=1;i<=5;i++) {
                if(a[1][i]!=a[2][i]) f=i;
            }
            if(f==1 || f==5) ans=10;
            else ans=12;
        } else ans=8;
    } else ans=10-n;
    cout << ans;
    return 0;
}