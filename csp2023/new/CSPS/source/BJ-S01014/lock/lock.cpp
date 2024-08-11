#include<bits/stdc++.h>
using namespace std;
int k[10][10],g[10];
int s[25]={0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>k[i][j];
    for(int a=0;a<10;a++)
    {
        for(int b=0;b<10;b++)
        {
            for(int c=0;c<10;c++)
            {
                for(int d=0;d<10;d++)
                {
                    for(int e=0;e<10;e++)
                    {
                        int flag=0;
                        g[1]=a,g[2]=b,g[3]=c,g[4]=d,g[5]=e;
                        for(int i=1;i<=n;i++)
                        {
                            if(flag==0&&i!=1) break;
                            int t=0,p[3];
                            for(int j=1;j<=5;j++)
                            {
                                if(k[i][j]!=g[j])
                                {
                                    t++;
                                    p[t]=j;
                                }
                            }
                            if(t>2)
                            {
                                flag=0;
                                break;
                            }
                            if(t==2&&(abs(p[1]-p[2])!=1))
                            {
                                flag=0;
                                break;
                            }
                            if(t==2)
                            {
                                int q=g[p[1]],w=g[p[2]],f=0;
                                for(int j=1;j<=10;j++)
                                {
                                    q++,w++;
                                    if(q%10==k[i][p[1]]&&w%10==k[i][p[2]])
                                    {
                                        f=1;
                                        break;
                                    }
                                }
                                if(f)
                                {
                                    flag=1;
                                    continue;
                                }
                                else flag=0;
                            }
                            if(t==1)
                            {
                                flag=1;
                                continue;
                            }
                            flag=0;
                        }
                        if(flag)
                            ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
