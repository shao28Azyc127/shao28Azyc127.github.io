#include <bits/stdc++.h>

using namespace std;
int n,m;
int ans[3003],a1[30],b1[30];
int wm1=30,sum1,cnt;
char s1[3003];
struct node{
    int w1,sw1,w2,sw2;
    char s[3003];
}t1[3003];
void find(int x)
{
    for(int j=1;j<=m;j++)
        {
            int t=t1[x].s[j]-'a';
            if(t==t1[x].w1)
            {
                t1[x].sw1+=1;
            }
            if(t<t1[x].w1)
            {
                t1[x].w1=t;
                t1[x].sw1=1;
            }
            if(t==t1[x].w2)
            {
                t1[x].sw2+=1;
            }
            if(t>t1[x].w2)
            {
                t1[x].w2=t;
                t1[x].sw2=1;
            }
        }
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",t1[i].s+1);
        t1[i].w1=30;
        t1[i].w2=-1;
        t1[i].sw1=0;
        t1[i].sw2=0;
        find(i);


        if(t1[i].w2<wm1||(t1[i].w2==wm1&&t1[i].sw2>sum1))
        {
            cnt=i;
            wm1=t1[i].w2;
            sum1=t1[i].sw2;
        }
    }
    ans[cnt]=1;
    for(int i=1;i<=n;i++)
    {


        if(t1[i].w1<wm1||(t1[i].w1==wm1&&t1[i].sw1<sum1))
        {
            ans[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
