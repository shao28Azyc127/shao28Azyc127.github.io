#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int q,m; scanf("%d%d",&q,&m);
    for(int i = 1;i <= q;i++){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        int delta = b * b - 4 * a * c;
        if(delta < 0) printf("NO\n");
        else{
            int coef = 1;
            if(a < 0) coef = -1;
            int rt = 0;
            for(int i = 1;i * i <= delta;i++)
                if(i * i == delta) rt = i;
            if(rt > 0 || delta == 0){
                int x = -1 * b + coef * rt, y = 2 * a;
                int div = __gcd(abs(x),abs(y));
                x /= div; y /= div;
                int flag = -1;
                if((x < 0 && y < 0) || (x > 0 && y > 0)) flag = 1;
                x = abs(x); y = abs(y);
                if(x == 0) printf("0\n");
                else{
                    if(flag == -1) printf("-");
                    if(y == 1) printf("%d\n",x);
                    else printf("%d/%d\n",x,y);
                }
            }
            else{
                int px = -1 * b, py = 2 * a;
                int qx = 1, qy = abs(2 * a);
                int div = __gcd(abs(px),abs(py));
                px /= div; py /= div;
                int flag = -1;
                if((px < 0 && py < 0) || (px > 0 && py > 0)) flag = 1;
                px = abs(px); py = abs(py);
                if(px != 0){
                    if(flag == -1) printf("-");
                    if(py == 1) printf("%d+",px);
                    else printf("%d/%d+",px,py);
                }
                for(int i = 2;i * i <= delta;i++)
                    while(delta % (i * i) == 0) qx *= i, delta /= i * i;
                div = __gcd(qx,qy); qx /= div; qy /= div;
                if(qx != 1) printf("%d*",qx);
                printf("sqrt(%d)",delta);
                if(qy != 1) printf("/%d",qy);
                printf("\n");
            }
        }
    }
    return 0;
}