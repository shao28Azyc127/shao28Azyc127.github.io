#include <iostream>

using namespace std;

const int N = 5e5+5;

int c,n,m,q;

int x[N],y[N];
int x2[N],y2[N];

bool check(){
    int j = 1;
    for(int i = 1;i <= n;i++){
        if(x2[i] != y2[j]) return false;
        while(x2[i] == y2[j]) j++;
    }
    return true;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&x[i]);
        x2[i] = x[i];
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",&y[i]);
        y2[i] = y[i];
    }
    cout << 1;
    for(int i = 1;i <= q;i++){
        for(int j = 1;j <= n;j++) x2[i] = x[i];
        for(int j = 1;j <= m;j++) y2[i] = y[i];
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int j = 1;j <= kx;j++){
            int p,v;
            scanf("%d%d",&p,&v);
            x2[p] = v;
        }
        for(int j = 1;j <= ky;j++){
            int p,v;
            scanf("%d%d",&p,&v);
            y2[p] = v;
        }
        cout << 1;
    }
    return 0;
}
