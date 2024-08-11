#include<iostream>
using namespace std;
int a[10][10];
signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if(n==1)
    {
        printf("%d",81);
        return 0;
    }
    int ans=0;
    for(int t1=0;t1<=9;t1++)
        for(int t2=0;t2<=9;t2++)
            for(int t3=0;t3<=9;t3++)
                for(int t4=0;t4<=9;t4++)
                    for(int t5=0;t5<=9;t5++)
                    {
                        int flag=1;
                        int res=0;
                        int b[6]={0,t1,t2,t3,t4,t5};
                        for(int i=1;i<=n;i++)
                        {
                            res=0;    
                            int p[3];int pcnt=1;
                            for(int j=1;j<=5;j++)
                            {
                                if(b[j]!=a[i][j])
                                {
                                    p[pcnt++]=j;
                                    res++;
                                }
                                if(res>2){flag=0; break;}
                                if(res==2)
                                {
                                    if(p[2]-p[1]>1){flag=0; break;}
                                    int f=0;
                                    for(int t=1;t<=10;t++)
                                    {
                                        if((a[i][p[1]]+t)%10==b[p[1]]&&(a[i][p[2]]+t)%10==b[p[2]])
                                        {
                                            f=1;break;
                                        }
                                    }
                                    if(!f)
                                    {
                                        flag=0; break;
                                    }
                                }
                            }
                            if(res==0||res>2){flag=0; break;}
                        }
                        if(flag)
                        {
                            ans++;
                        }
                    }
    printf("%d",ans);
    return 0;
}