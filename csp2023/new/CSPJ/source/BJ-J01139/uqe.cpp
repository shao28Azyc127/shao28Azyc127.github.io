#include <bits/stdc++.h>

using namespace std;
int T,m;
int a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&m);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(b == 0&&c == 0) {printf("0\n");continue;}
        if(pow(b,2)-4*a*c<0) {printf("NO\n");continue;}
        if(b == 0)
        {
            if(abs(c)%abs(a) == 0)
            {
                printf("%d\n",sqrt(abs(c)/abs(a)));
            }
        }
    }
    return 0;
}
