#include<bits/stdc++.h>
using namespace std;
const int MAXN=10;
struct lock{
    int a,b,c,d,e;
}K[MAXN];
struct Lock{
    int a,b,c,d,e;
    int flag=0,amt=0;
}k[MAXN*81];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>K[i].a>>K[i].b>>K[i].c>>K[i].d>>K[i].e;
    }
    if(n==1)cout<<"81"<<endl;
    else{
        for(int i=1;i<=n;i++)
        {
            for(int q=0;q<9;q++)
            {
                for(int j=1;j<=9;j++)
                {
                    if(q==0) k[i*81+j-1].a=(K[i].a+j)%10,k[i*81+j-1].b=K[i].b,k[i*81+j-1].c=K[i].c,k[i*81+j-1].d=K[i].d,k[i*81+j-1].e=K[i].e;
                    else if(q==1) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=(K[i].b+j)%10,k[i*81+q*9+j-1].c=K[i].c,k[i*81+q*9+j-1].d=K[i].d,k[i*81+q*9+j-1].e=K[i].e;
                    else if(q==2) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=K[i].b,k[i*81+q*9+j-1].c=(K[i].c+j)%10,k[i*81+q*9+j-1].d=K[i].d,k[i*81+q*9+j-1].e=K[i].e;
                    else if(q==3) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=K[i].b,k[i*81+q*9+j-1].c=K[i].c,k[i*81+q*9+j-1].d=(K[i].d+j)%10,k[i*81+q*9+j-1].e=K[i].e;
                    else if(q==4) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=K[i].b,k[i*81+q*9+j-1].c=K[i].c,k[i*81+q*9+j-1].d=K[i].d,k[i*81+q*9+j-1].e=(K[i].e+j)%10;
                    else if(q==5) k[i*81+q*9+j-1].a=(K[i].a+j)%10,k[i*81+q*9+j-1].b=(K[i].b+j)%10,k[i*81+q*9+j-1].c=K[i].c,k[i*81+q*9+j-1].d=K[i].d,k[i*81+q*9+j-1].e=K[i].e;
                    else if(q==6) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=(K[i].b+j)%10,k[i*81+q*9+j-1].c=(K[i].c+j)%10,k[i*81+q*9+j-1].d=K[i].d,k[i*81+q*9+j-1].e=K[i].e;
                    else if(q==7) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=K[i].b,k[i*81+q*9+j-1].c=(K[i].c+j)%10,k[i*81+q*9+j-1].d=(K[i].d+j)%10,k[i*81+q*9+j-1].e=K[i].e;
                    else if(q==8) k[i*81+q*9+j-1].a=K[i].a,k[i*81+q*9+j-1].b=K[i].b,k[i*81+q*9+j-1].c=K[i].c,k[i*81+q*9+j-1].d=(K[i].d+j)%10,k[i*81+q*9+j-1].e=(K[i].e+j)%10;
                }
            }

        }
        for(int i=81;i<=81+8*9+9-1;i++)
        {
            for(int j=2*81;j<=3*81-1;j++)
            {
                if(k[i].a==k[j].a&&k[i].b==k[j].b&&k[i].c==k[j].c&&k[i].d==k[j].d&&k[i].e==k[j].e)
                {
                    k[i].flag=k[j].flag=sum;
                    sum++;
                    k[i].amt+=2;
                }
            }
        }
        for(int i=81;i<=2*81-1;i++)
        {
            if(k[i].flag==0)continue;
            else{
                for(int j=3*81;j<=4*81-1;j++)
                {
                    if(k[i].a==k[j].a&&k[i].b==k[j].b&&k[i].c==k[j].c&&k[i].d==k[j].d&&k[i].e==k[j].e)
                    {
                        k[j].flag=k[i].flag;
                        k[i].amt++;
                    }
                }
            }
        }
        for(int i=81;i<=2*81-1;i++)
        {
            if(k[i].flag==0)continue;
            else{
                for(int j=4*81;j<=5*81-1;j++)
                {
                    if(k[i].a==k[j].a&&k[i].b==k[j].b&&k[i].c==k[j].c&&k[i].d==k[j].d&&k[i].e==k[j].e)
                    {
                        k[j].flag=k[i].flag;
                        k[i].amt++;
                    }
                }
            }
        }
        for(int i=81;i<=2*81-1;i++)
        {
            if(k[i].flag==0)continue;
            else{
                for(int j=5*81;j<=6*81-1;j++)
                {
                    if(k[i].a==k[j].a&&k[i].b==k[j].b&&k[i].c==k[j].c&&k[i].d==k[j].d&&k[i].e==k[j].e)
                    {
                        k[j].flag=k[i].flag;
                        k[i].amt++;
                    }
                }
            }
        }
        for(int i=81;i<=2*81-1;i++)
        {
            if(k[i].flag==0)continue;
            else{
                for(int j=6*81;j<=7*81-1;j++)
                {
                    if(k[i].a==k[j].a&&k[i].b==k[j].b&&k[i].c==k[j].c&&k[i].d==k[j].d&&k[i].e==k[j].e)
                    {
                        k[j].flag=k[i].flag;
                        k[i].amt++;
                    }
                }
            }
        }
        for(int i=81;i<=2*81-1;i++)
        {
            if(k[i].flag==0)continue;
            else{
                for(int j=7*81;j<=8*81-1;j++)
                {
                    if(k[i].a==k[j].a&&k[i].b==k[j].b&&k[i].c==k[j].c&&k[i].d==k[j].d&&k[i].e==k[j].e)
                    {
                        k[j].flag=k[i].flag;
                        k[i].amt++;
                    }
                }
            }
        }
        int ans=0;
        for(int i=81;i<=2*81-1;i++)
        {
            if(k[i].amt==n)
            {
                ans++;
                //cout<<k[i].a<<" "<<k[i].b<<" "<<k[i].c<<" "<<k[i].d<<" "<<k[i].e<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
