#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    while(n--){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(b==0&&c==0)
            printf("0\n");
        else
        {

            long long x=b*b-4*a*c;
            if(x<0)
                printf("NO\n");
            else
            {

                long long p1=(-b+sqrt(x))/(2*a);
                long long p2=(-b-sqrt(x))/(2*a);
                long long p=max(p1,p2);
                if(p==1||p==0||p==-1)
                    printf("%lld\n",p);
                else
                    printf("%lld/%lld\n",p,1);
            }

        }
    }
}
