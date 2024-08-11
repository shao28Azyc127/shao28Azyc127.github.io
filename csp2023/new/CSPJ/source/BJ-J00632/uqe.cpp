#include<bits/stdc++.h>
using namespace std;
int t,m,i,j,tmp,cnt = 1;
int a,b,c,gcd1,gcd2,flag;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(i = 1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(b*b<4*a*c)
        {
            cout<<"NO\n";
        }
        else if(b%(2*a) == 0)
        {
            tmp = 4*a*c;
            if(1.0*sqrt(b*b-tmp) == 1.0*int(sqrt(b*b-tmp))&&c%a == 0)
            {
                cout<<(int(sqrt(b*b-tmp))-b)/2*a<<"\n";
            }
            else if(1.0*sqrt(b*b-tmp) == 1.0*int(sqrt(b*b-tmp)))
            {
                gcd1 = __gcd((int(sqrt(b*b-tmp))-b),2*a);
                cout<<(int(sqrt(b*b-tmp))-b)/gcd1<<'/'<<(2*a)/gcd1<<"\n";
            }
            else
            {
                for(j = 2;j*j<=tmp;j++)
                {
                    if(tmp%(j*j) == 0)
                    {
                        cnt*=j;
                        flag = 1;
                    }
                }
                if(flag)
                {
                    printf("%d+%d*sqrt(%d)\n",(-1*b)/(2*a),cnt,(b*b-tmp)/(cnt*cnt));
                    flag = 0;
                    cnt = 1;
                }
                else
                {
                    printf("%d+sqrt(%d)\n",(-1*b)/(2*a),(b*b-tmp));
                }
            }
        }
        else
        {
            tmp = 4*a*c;
            if(1.0*sqrt(b*b-tmp) == 1.0*int(sqrt(b*b-tmp))&&(int(sqrt(b*b-tmp))-b)%a == 0)
            {
                cout<<(int(sqrt(b*b-tmp))-b)/2*a<<"\n";
            }
            else if(1.0*sqrt(b*b-tmp) == 1.0*int(sqrt(b*b-tmp)))
            {
                gcd1 = __gcd((int(sqrt(b*b-tmp))-b),2*a);
                cout<<(int(sqrt(b*b-tmp))-b)/gcd1<<'/'<<(2*a)/gcd1<<"\n";
            }
            else
            {
                gcd1 = __gcd(-1*b,2*a);
                for(j = 2;j*j<=tmp;j++)
                {
                    if(tmp%(j*j) == 0)
                    {
                        cnt*=j;
                        flag = 1;
                    }
                }
                if(flag)
                {
                    gcd2 = __gcd((b*b-tmp)/(cnt*cnt),2*a);
                    if(2*a/gcd2 == 1)
                    {
                        printf("%d/%d+%d*sqrt(%d)\n",(-1*b)/gcd1,(2*a)/gcd1,cnt,(b*b-tmp)/(cnt*cnt)/gcd2);
                    }
                    else
                    {
                        printf("%d/%d+%d*sqrt(%d)/%d\n",(-1*b)/gcd1,(2*a)/gcd1,cnt,(b*b-tmp)/(cnt*cnt)/gcd2,2*a/gcd2);
                    }
                    flag = 0;
                    cnt = 1;
                }
                else
                {
                    gcd2 = __gcd((b*b-tmp),2*a);
                    if(2*a/gcd2 == 1)
                    {
                        printf("%d/%d+%d*sqrt(%d)\n",(-1*b)/gcd1,(2*a)/gcd1,cnt,(b*b-tmp)/gcd2);
                    }
                    else
                    {
                        printf("%d/%d+%d*sqrt(%d)/%d\n",(-1*b)/gcd1,(2*a)/gcd1,cnt,(b*b-tmp)/gcd2,2*a/gcd2);
                    }
                }
            }

        }
    }
    return 0;
}
