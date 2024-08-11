#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m;
char op;
int u,v;
struct Node
{
    char val;
    int vu;
    bool fl;
}x[N];
int fa[N<<1],sum[N<<1];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
    int rx=find(x),ry=find(y);
    if(rx==ry)return;
    fa[ry]=rx;
    sum[rx]+=sum[ry];
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            x[i].val='-';
            x[i].vu=i;
            x[i].fl=0;
            fa[i]=i;
            sum[i]=1;
        }
        for(int i=n+1;i<=2*n+3;i++)
        {
            fa[i]=i;
            sum[i]=0;
        }
        while(m--)
        {
            scanf(" %c",&op);
            switch(op)
            {
                case 'T':
                    {
                        scanf(" %d",&u);
                        x[u].fl=0;
                        x[u].val=op;
                        x[u].vu=-1;
                        break;
                    }
                case 'F':
                    {
                        scanf(" %d",&u);
                        x[u].fl=0;
                        x[u].val=op;
                        x[u].vu=-1;
                        break;
                    }
                case 'U':
                    {
                        scanf(" %d",&u);
                        x[u].fl=0;
                        x[u].val=op;
                        x[u].vu=-1;
                        break;
                    }
                case '+':
                    {
                        scanf(" %d %d",&u,&v);
                        if(x[v].val!='-')
                        {
                            x[u].fl=0;
                            x[u].val=x[v].val;
                            x[u].vu=-1;
                        }
                        else
                        {
                            x[u].fl=x[v].fl;
                            x[u].val='-';
                            x[u].vu=x[v].vu;
                        }
                        break;
                    }
                case '-':
                    {
                        scanf(" %d %d",&u,&v);
                        if(x[v].val!='-')
                        {
                            x[u].fl=0;
                            if(x[v].val=='T'){x[u].val='F';}
                            else if(x[v].val=='F'){x[u].val='T';}
                            else if(x[v].val=='U'){x[u].val='U';}
                            x[u].vu=-1;
                        }
                        else
                        {
                            x[u].fl=!x[v].fl;
                            x[u].val='-';
                            x[u].vu=x[v].vu;
                        }
                        break;
                    }
            }
        }
        for(int i=1;i<=n;i++)
        {
            //printf("%d:%c %d %d\n",i,x[i].val,x[i].vu,x[i].fl);
            if(x[i].val!='-')
            {
                if(x[i].val=='T')
                {
                    merge(2*n+1,i);
                    merge(2*n+2,i+n);
                }
                else if(x[i].val=='F')
                {
                    merge(2*n+2,i);
                    merge(2*n+1,i+n);
                }
                else if(x[i].val=='U')
                {
                    merge(2*n+3,i);
                    merge(2*n+3,i+n);
                }
            }else{
                if(!x[i].fl)
                {
                    merge(x[i].vu,i);
                    merge(x[i].vu+n,i+n);
                }
                else
                {
                    merge(x[i].vu+n,i);
                    merge(x[i].vu,i+n);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(find(i)==find(i+n))merge(2*n+3,i);
        }
        /*for(int j=1;j<=2*n+3;j++)
        {
            if(fa[j]==j&&sum[j])
            {
                printf("%d %d\n",j,sum[j]);
            }
        }
        putchar('\n');
        if(c==3||c==4)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(x[i].val=='U')cnt++;
            }
            printf("%d\n",cnt);
        }*/
        printf("%d\n",sum[find(2*n+3)]);
    }

    return 0;
}
