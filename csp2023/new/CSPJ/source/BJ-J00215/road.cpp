#include <bits/stdc++.h>
using namespace std;

struct zd{
    int v,a;
}a[100000];

struct dp{
    int f,yy;
}f[100000];
int n;


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    double d;
    scanf("%d",&n);
    cin >> d;
    for(int i = 0;i < n - 1;i++){
        scanf("%d",&a[i].v);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i].a);
    }
    f[0].f = 0;
    f[0].yy = 0;
    f[1].f = ceil(a[0].v / d) * a[0].a;
    f[1].yy = a[0].v % int(d);
    for(int i = 2;i < n;i++){
        long long mn = 9223300000000000000,yymn,sum = 0,pri;
        for(int j = i-1;j >= 0;j--){
            sum += a[j].v;
            if(sum % int(d) && (sum - f[j].yy) % int(d)){
                pri = ceil(ceil(sum - f[j].yy) / d) * a[j].a + f[j].f;
            }
            else if((sum - f[j].yy) % int(d)){
                pri = sum / d * a[j].a + f[j].f;
                yymn = (sum - f[j].yy) % int(d);
            }
            else{
                pri = (sum - f[j].yy) / d * a[j].a + f[j].f;
                yymn = 0;
            }
            mn = min(mn,pri);
        }
        f[i].yy = yymn;
        f[i].f= mn;
    }
    printf("%d",f[n-1]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
