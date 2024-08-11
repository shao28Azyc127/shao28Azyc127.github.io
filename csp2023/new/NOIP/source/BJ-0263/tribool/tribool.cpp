#include<bits/stdc++.h>
using namespace std;

int fi[100010];
const int T=100001 , F=-100001 , U=0;
int c,t; int n,m;
char v; int x,y;
int fa[200022] , si[200022];

void Clear()
{
    for(int i=T+F;i<=T+T;i++)
    {fa[i]=i;si[i]=1;}
    for(int i=1;i<=100000;i++)fi[i]=i;
    si[T+T]=si[T+F]=si[T+U]=1e6+1;
}

int Find(int xx)
{
    return (fa[xx]==xx)?xx:(fa[xx]=Find(fa[xx]));
}

void Merge(int xx,int yy)
{
    int fx=Find(xx),fy=Find(yy);
    if(fx==fy)return;
    if(si[fx]>si[fy])
    {
        si[fx]+=si[fy];fa[fy]=fx;
    }
    else
    {
        si[fy]+=si[fx];fa[fx]=fy;
    }
}

void check(int xx,int yy)
{
    if(Find(xx)==Find(2*T-xx))
    {
        Merge(Find(xx),T+U);
    }
    if(Find(yy)==Find(2*T-yy))
    {
        Merge(Find(yy),T+U);
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        Clear();
        //inputsth
        for(int i=1;i<=m;i++)
        {
            scanf("%c%c",&v,&v);
            if(v=='T')
            {
                scanf("%d",&x);
                fi[x]=T;
            }
            if(v=='F')
            {
                scanf("%d",&x);
                fi[x]=F;
            }
            if(v=='U')
            {
                scanf("%d",&x);
                fi[x]=U;
            }
            if(v=='+')
            {
                scanf("%d%d",&x,&y);
                fi[x]=fi[y];
            }
            if(v=='-')
            {
                scanf("%d%d",&x,&y);
                fi[x]=fi[y]*-1;
            }
        }
        /*
        for(int i=1;i<=n;i++)
        {
            printf("%d ",fi[i]);
        }*/
        for(int i=1;i<=n;i++)
        {
            if(i!=fi[i])
            {
                Merge(T+i,T+fi[i]);Merge(T-i,T-fi[i]);check(T+i,T+fi[i]);
            }
        }
        /*
        for(int i=T-n;i<=T+n;i++)
        {
            printf("%d %d ",fa[i],si[i]);
        }*/
        printf("%d\n",(si[T+U]-1000000)/2);
    }
    return 0;
}
