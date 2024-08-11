#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,n;
    scanf("%d%d",&t,&n);
    while(t--)
    {
        long long a,b,c,aa;
        double xx,xy;
        cin>>a>>b>>c;
        aa=b*b-4*a*c;
        if(aa<0)  printf("NO\n");
        else
        {
            /*xx=(-b+sqrt(aa))/(2*a);
            xy=(-b-sqrt(aa))/(2*a);
            if(xx<xy) swap(xx,xy);
            if()*/
            bool f=0;
            for(int i=n;i>=-n;i--)
            {
                if(a*i*i+b*i+c==0)
                {
                    printf("%d\n",i);
                    f=1;
                    break;
                }
            }
            if(!f) printf("NO\n");
        }
    }
    return 0;
}
