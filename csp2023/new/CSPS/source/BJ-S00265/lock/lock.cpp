#include <iostream>

using namespace std;

int a[6],n;
int b[10][6];

void ntoa(int x)
{
    for(int i=5;i>=1;i--)
    {
        a[i]=x%10;
        x/=10;
    }
}

int aton()
{
    return a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
}

bool allow(int k,int p1,int p2)
{
    int x1=a[p1],x2=a[p2],y1=b[k][p1],y2=b[k][p2];
    if(x1>x2)x2+=10;
    if(y1>y2)y2+=10;
    if(y2-y1==x2-x1)return 1;
    return 0;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>b[i][j];
        }
    }
    if(n==1)
    {
        cout<<81;
        return 0;
    }
    for(int i=0;i<100000;i++)
    {
        ntoa(i);
        bool flag=1;
        for(int k=1;k<=n;k++)//k¸ö¾ùÂú×ã
        {
            int s=0,p1,p2;
            for(int j=1;j<=5;j++)
            {
                if(a[j]!=b[k][j])
                {
                    s++;
                    if(s==1)p1=j;
                    else p2=j;
                }
            }
            if(s==0||s>2|| (s==2&&p2-p1!=1))
            {
                flag=0;break;
            }
            if(s==2&& !allow(k,p1,p2))
            {
                flag=0;break;
            }
        }
        if(flag)ans++;
    }
    cout<<ans;
    return 0;
}
