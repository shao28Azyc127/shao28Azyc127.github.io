#include <bits/stdc++.h>

using namespace std;

int c,t,m,n;
int i,j;
char v;
int a,b;
int cnt;

int x[100005];//T=1 F=0 U=2

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    scanf("%d%d",&c,&t);

    if(c==3||c==4)
    {
        for(i=1;i<=t;++i)
        {
            cnt=0;
            memset(x,1,sizeof(x));

            scanf("%d%d",&n,&m);

            for(j=1;j<=m;++j)
            {
                cin>>v;
                scanf("%d",&a);

                if(v=='U')
                {
                    x[a]=2;
                }
            }

            for(j=1;j<=n;++j)
            {
                if(x[j]=2)
                {
                    cnt++;
                }
            }

            printf("%d\n",cnt);
        }
    }

    if(c==5||c==6)//wrong
    {
        for(i=1;i<=t;++i)
        {
            cnt=0;
            memset(x,1,sizeof(x));

            scanf("%d%d",&n,&m);

            for(j=1;j<=m;++j)
            {
                cin>>v;
                scanf("%d",&a);

                if(v=='U')
                {
                    x[a]=2;
                }
                else
                {
                    scanf("%d",&b);
                    x[a]=x[b];
                }
            }

            for(j=1;j<=n;++j)
            {
                if(x[j]=2)
                {
                    cnt++;
                }
            }

            printf("%d\n",cnt);
        }
    }

    if(c==7||c==8)
    {
        for(i=1;i<=t;++i)
        {
            cnt=0;
            memset(x,-1,sizeof(x));

            scanf("%d%d",&n,&m);

            for(j=1;j<=m;++j)
            {
                cin>>v;
                scanf("%d%d",&a,&b);

                if(v=='+')
                {
                    if(x[a]==-1&&x[b]!=-1)
                    {
                        x[a]=x[b];
                    }
                    if(x[a]==-1&&x[b]==-1)
                    {
                        x[a]=x[b]=1;
                    }
                    if(x[a]!=-1&&x[b]==-1)
                    {
                        x[b]=x[a];
                    }
                    if(x[a]!=-1&&x[b]!=-1)
                    {
                        if(x[a]!=x[b])
                        {
                            x[a]=2;
                        }
                    }
                }
                else if(v=='-')
                {
                    x[b]=1-x[b];
                    if(x[b]==-1)
                    {
                        x[b]=2;
                    }

                    if(x[a]==-1&&x[b]!=-1)
                    {
                        x[a]=x[b];
                    }
                    if(x[a]==-1&&x[b]==-1)
                    {
                        x[a]=x[b]=1;
                    }
                    if(x[a]!=-1&&x[b]==-1)
                    {
                        x[b]=x[a];
                    }
                    if(x[a]!=-1&&x[b]!=-1)
                    {
                        if(x[a]!=x[b])
                        {
                            x[a]=2;
                        }
                    }
                }
            }

            for(j=1;j<=n;++j)
            {
                if(x[j]=2)
                {
                    cnt++;
                }
            }

            printf("%d\n",cnt);
        }
    }

    return 0;
}
