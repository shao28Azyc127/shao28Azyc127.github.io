#include <bits/stdc++.h>
using namespace std;
int n,v[9],b[9],f;
int ans,z,y,x,a[9];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i]=0;
        for(int j=0;j<5;j++)
        {
            cin>>y;
            a[i]=a[i]*10+y;
        }
    }
    for(b[0]=0;b[0]<10;b[0]++)
    {
        for(b[1]=0;b[1]<10;b[1]++)
        {
            for(b[2]=0;b[2]<10;b[2]++)
            {
                for(b[3]=0;b[3]<10;b[3]++)
                {
                    for(b[4]=0;b[4]<10;b[4]++)
                    {
                        memset(v,0,sizeof(v));
                        for(int j=0;j<5;j++)
                        {
                            x=b[j];
                            for(int k=1;k<=9;k++)
                            {
                                b[j]=(b[j]+k)%10;
                                y=0;
                                for(int p=0;p<5;p++)
                                {
                                    y=y*10+b[p];
                                }
                                for(int p=0;p<n;p++)
                                {
                                    if(y==a[p]&&!v[p])
                                    {
                                        v[p]=1;
                                        f++;
                                    }
                                }
                                b[j]=x;
                            }
                        }
                        for(int j=0;j<4;j++)
                        {
                            x=b[j];
                            y=b[j+1];
                            for(int k=1;k<=9;k++)
                            {
                                b[j]=(b[j]+k)%10;
                                b[j+1]=(b[j+1]+k)%10;
                                z=0;
                                for(int p=0;p<5;p++)
                                {
                                    z=z*10+b[p];
                                }
                                for(int p=0;p<n;p++)
                                {
                                    if(z==a[p]&&!v[p])
                                    {
                                        v[p]=1;
                                        f++;
                                    }
                                }
                                b[j]=x;
                                b[j+1]=y;
                            }
                        }
                        if(f==n)
                        {
                            ans++;
                        }
                        f=0;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
