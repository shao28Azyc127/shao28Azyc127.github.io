#include<bits/stdc++.h>
using namespace std;
int ed[100005];
int *e[100005];
inline int code(char c) {
    if (c=='T') return 1;
    else if (c=='F') return 0;
    return -1;
}
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d %d\n",&c,&t);
    if (c<=2) {

    }
    else if (c<=4) {
        while (t--) {
            int n,m,cnt=0;
            scanf("%d %d\n",&n,&m);
            for (int i=1;i<=m;i++) {
                char v;
                int x;
                scanf("%c %d\n",&v,&x);
                ed[x]=code(v);
            }
            for (int i=1;i<=n;i++) {
                if (ed[i]==-1) {
                    cnt++;
                }
            }
            printf("%d\n",cnt);
            for (int i=1;i<=n;i++) ed[i]=0;
        }
    }
    else if (c<=6) {
        while (t--) {
            int n,m,cnt=0;
            scanf("%d %d\n",&n,&m);
            for (int i=1;i<=m;i++) {
                char v;
                scanf("%c ",&v);
                if (v=='U') {
                    int x;
                    scanf("%d\n",&x);
                    ed[x]=-1;
                }
                else {
                    int x,y;
                    scanf("%d %d\n",&x,&y);
                    e[x]=e[y];
                    ed[x]=ed[y];
                }
            }
            for (int i=1;i<=n;i++) {
                if (ed[i]==-1) {
                    cnt++;
                }
            }
            printf("%d\n",cnt);
            for (int i=1;i<=n;i++) ed[i]=0;
        }
    }
    else if (c<=8) {

    }
    else {

    }
    return 0;
}
