#include<bits/stdc++.h>
using namespace std;
int calc(int x)
{
    int maxx=1;
    for(int i=1;i*i<=x;++i)
        if(x%(i*i)==0)maxx=i;
    return maxx;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;cin>>t>>m;while(t--)
    {
        int a,b,c;cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0)printf("NO\n");
        else if(delta==0)
        {
            if(b==0)
            {
                printf("0\n");
                continue;
            }
            bool p=(a*b<0);
            a=abs(a)*2,b=abs(b);
            int yf=__gcd(a,b);
            a/=yf;b/=yf;
            if(!p)printf("-");
            if(a==1)printf("%d\n",b);
            else printf("%d/%d\n",b,a);
        }
        else
        {
            //bigger
            int ans=calc(delta);
            int xx=delta/(ans*ans);
            //-b/2a case
            if(b!=0)
            {
                bool p=(a*b<0);
                /*if(ans==1)
                {
                    if(!p)printf("-");
                    if(abs((xx-b))%abs(2*a)==0)
                        printf("%d",abs((xx-b))/abs(2*a));
                }
                else */if(xx==1)
                {
                    if(!p)printf("-");
                    if(abs(ans-b)%abs(2*a)==0)
                        printf("%d",abs(ans-b)/abs(2*a));
                }
                else
                {
                    a=abs(a)*2,b=abs(b);
                    int yf=__gcd(a,b);
                    a/=yf;b/=yf;
                    if(!p)printf("-");
                    if(a==1)printf("%d",b);
                    else printf("%d/%d",b,a);
                }
                if(ans==1 or abs((xx-b))%abs(2*a)==0)printf("");
                else printf("+");
            }
            //sqrt case
            printf("\n");
        }
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
