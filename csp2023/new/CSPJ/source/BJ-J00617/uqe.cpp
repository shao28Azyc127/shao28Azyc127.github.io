#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    while (t>0)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (b*b-4*a*c<0)
        {
            printf("NO");
            continue;
        }
        printf("%d\n",(-b+sqrt(b*b-4*a*c))/(2*a));
        t--;
    }
    return 0;
}
