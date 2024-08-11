#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n,a[N],b[N],c[N],d[N],e[N],ans;
bool get(int x,int y,int xx,int yy){
    int z = x - xx,zz = y - yy;
    if(z < 0) z += 10;
    if(zz < 0) zz += 10;
    return z != zz;
}
bool check(int A,int B,int C,int D,int E){
    for(int i = 1;i <= n;i++){
        int q[N],p[N],id[N],cnt = 0;
        if(A != a[i]) q[++cnt] = A,p[cnt] = a[i],id[cnt] = 1;
        if(B != b[i]) q[++cnt] = B,p[cnt] = b[i],id[cnt] = 2;
        if(C != c[i]) q[++cnt] = C,p[cnt] = c[i],id[cnt] = 3;
        if(D != d[i]) q[++cnt] = D,p[cnt] = d[i],id[cnt] = 4;
        if(E != e[i]) q[++cnt] = E,p[cnt] = e[i],id[cnt] = 5;
        if(cnt > 2 || cnt < 1) return 0;
        if(cnt > 1 && ((id[2] - id[1] != 1) || get(q[1],p[1],q[2],p[2])))
            return 0;
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i]);
    }
    for(int A = 0;A <= 9;A++)
        for(int B = 0;B <= 9;B++)
            for(int C = 0;C <= 9;C++)
                for(int D = 0;D <= 9;D++)
                    for(int E = 0;E <= 9;E++){
                        if(check(A,B,C,D,E)) ans++;
                    }
    printf("%d\n",ans);
    return 0;
}