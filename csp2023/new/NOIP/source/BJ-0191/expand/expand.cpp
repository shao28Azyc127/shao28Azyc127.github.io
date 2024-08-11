#include <cstdio>
#include <iostream>
using namespace std;
int c,n,m,q,x[10],y[10],a[10],b[10],kx,ky,p,v;
bool ans;
bool check(int ptx,int pty){
    if(a[1] < b[1] && a[ptx] < b[pty]) return 1;
    if(a[1] > b[1] && a[ptx] > b[pty]) return 1;
    return 0;
}
void calc(int ptx,int pty){
    if(ans) return;
    if(ptx < n && check(ptx + 1,pty)) calc(ptx + 1,pty);
    if(pty < m && check(ptx,pty + 1)) calc(ptx,pty + 1);
    if(ptx < n && pty < m && check(ptx + 1,pty + 1));
    if(ptx == n && pty == m) ans = 1;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&x[i]);
        a[i] = x[i];
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",&y[i]);
        b[i] = y[i];
    }
    ans = 0;
    calc(1,1);
    if(ans) cout << 1;
    else cout << 0;
    while(q--){
        for(int i = 1;i <= n;i++) a[i] = x[i];
        for(int i = 1;i <= m;i++) b[i] = y[i];
        scanf("%d%d",&kx,&ky);
        for(int i = 1;i <= kx;i++){
            scanf("%d%d",&p,&v);
            a[p] = v;
        }
        for(int i = 1;i <= ky;i++){
            scanf("%d%d",&p,&v);
            b[p] = v;
        }
        ans = 0;
        calc(1,1);
        if(ans) cout << 1;
        else cout << 0;
    }
    return 0;
}