#include <bits/stdc++.h>
using namespace std;
int a[12][10];
int b[10];
int N,ans=0;
int c=0;
int Dis(int x,int y)
{
    if(x>y) return x-y;
    if(x==y) return 0;
    if(x<y) return x+1+9-y;
}
bool Check()
{
    for(int i=1;i<=N;i++)
    {
        int dif1=0,dif2=0;
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]!=b[j])
            {
                if(dif2) return false;
                if(dif1) dif2=j;
                else dif1=j;
            }
        }
        if(!dif1) return false;
        if(dif2)
        {
            if(dif1!=dif2-1) return false;
            if(Dis(a[i][dif1],b[dif1])!=Dis(a[i][dif2],b[dif2])) return false;
        }
    }
    //for(int i=1;i<=5;i++) printf("%d ",b[i]);
    //puts("--1--");
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
    }
    for(b[1]=0;b[1]<10;b[1]++)
    {
        for(b[2]=0;b[2]<10;b[2]++)
        {
            for(b[3]=0;b[3]<10;b[3]++)
            {
                for(b[4]=0;b[4]<10;b[4]++)
                {
                    for(b[5]=0;b[5]<10;b[5]++)
                    {
                        if(Check()) ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
