#include <cstdio>
int c,n,m,q,x[2005],y[2005],kx,ky,xx[2005],yy[2005],p,v;
bool dp[2005][2005],flag;
bool solve(int* a,int* b,int siza,int sizb){
    dp[0][0] = true;
    for(int i = 1;i <= sizb;i++){
        flag = dp[i - 1][0];
        for(int j = 1;j <= siza;j++){
            flag |= dp[i - 1][j];
            if(!dp[i - 1][j] && a[j] <= b[i]){
                flag = false;
            }
            dp[i][j] = flag & (a[j] > b[i]);
        }
    }
    return dp[sizb][siza];
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&x[i]);
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",&y[i]);
    }
    printf("%d",solve(x,y,n,m) | solve(y,x,m,n));
    while(q--){
        scanf("%d%d",&kx,&ky);
        for(int i = 1;i <= n;i++){
            xx[i] = x[i];
        }
        for(int i = 1;i <= m;i++){
            yy[i] = y[i];
        }
        while(kx--){
            scanf("%d%d",&p,&v);
            xx[p] = v;
        }
        while(ky--){
            scanf("%d%d",&p,&v);
            yy[p] = v;
        }
        printf("%d",solve(xx,yy,n,m) | solve(yy,xx,m,n));
    }
    return 0;
}
