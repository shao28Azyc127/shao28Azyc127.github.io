#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N=1e5+10;

int c,T;

int n,m;
int a[N*3+100],b[3*N];

int ans=0x3f3f3f3f;

void dfs(int level)
{
    if(level>n)
    {
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(b[i]==1)
            {
                if(!b[a[i]]) flag=0;
            }
            if(b[i+n]==1)
            {
                if(!b[a[i+n]]) flag=0;
            }
            if(b[i+2*n]==1)
            {
                if(!b[a[i+2*n]]) flag=0;
            }
        }
        int cnt=0;
        if(flag)
        {
            // for(int i=1;i<=n;i++)
            // {
            //     if(b[i]) printf("0 ");
            //     if(b[i+n]) printf("1 ");
            //     if(b[i+2*n]) printf("2 ");
            // }
            // printf("\n");
            for(int i=1;i<=n;i++) if(b[i+2*n]) cnt++;
            ans=min(ans,cnt);
        }
        return ;
    }
    for(int i=0;i<=2;i++)
    {
        // b[level]=b[level+n]=b[level+2*n]=i;
        if(i==0) b[level]=1;
        if(i==1) b[level+n]=1;
        if(i==2) b[level+2*n]=1;
        dfs(level+1);
        if(i==0) b[level]=0;
        if(i==1) b[level+n]=0;
        if(i==2) b[level+2*n]=0;
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d %d",&c,&T);
    while(T--)
    {
        bool plus=0;
        ans=0x3f3f3f3f;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=3*n+3;i++) a[i]=i;
        b[3*n+1]=b[3*n+2]=b[3*n+3]=1;
        for(int i=1;i<=m;i++)
        {
            char v;
            int x,y;
            cin>>v;
            scanf("%d",&x);
            if(v=='T')
            {
                a[x]=3*n+1;
                a[x+n]=a[x+2*n]=-1;
            }
            if(v=='F')
            {
                a[x+n]=3*n+2;
                a[x]=a[x+2*n]=-1;
            }
            if(v=='U')
            {
                a[x+2*n]=3*n+3;
                a[x+n]=a[x]=-1;
            }
            if(v=='+')
            {
                scanf("%d",&y);
                a[x]=a[y];
                a[x+n]=a[y+n];
                a[x+2*n]=a[y+2*n];
            }
            if(v=='-')
            {
                scanf("%d",&y);
                a[x]=a[y+n];
                a[x+n]=a[y];
                a[x+2*n]=a[y+2*n];
            }
            // printf("%d %d %d\n",a[x],a[x+n],a[x+2*n]);
        }
        // for(int i=1;i<=3*n;i++)
        // {
        //     printf("%d ",a[i]);
        //     if(i==n||i==2*n||i==3*n) printf("\n");
        // }
        if(n<=10)
        {
            dfs(1);
            printf("%d\n",ans);
            continue;
        }
        ans=0;
        for(int i=1;i<=n;i++) if(a[i+2*n]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}