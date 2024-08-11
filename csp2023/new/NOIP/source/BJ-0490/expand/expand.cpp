#include<bits/stdc++.h>
using namespace std;
int main () {
    int c,n,m,q;
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >>c>>n>>m>>q;
    if (n==1) {
        int x,y;
        cin >>x>>y;
        if (x==y) cout <<0;
        else cout <<1;
        for (int a=1;a<=q;a++) {
            int c,d;
            int e=x,f=y;
            cin >>c>>d;
            if (c) {
                cin >>e>>e;
            }
            if (d) {
                cin >>f>>f;
            }
            if (e==f) cout <<0;
            else cout <<1;
        }
    }
    return 0;
}
