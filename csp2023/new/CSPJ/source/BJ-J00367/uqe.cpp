#include<cstdio>

struct fs{
int u,d;
bool fuhao;
};

int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}

int pfs(int x)
{
    for(int i=0;i*i<=x;i++)
    {
        if(i*i==x)return i;
    }
    return -1;
}

int spfyz(int x)
{
    int sc=2;
    while(x>sc*sc)
    {
        if(x%(sc*sc)==0)
        {
            x=x/(sc*sc);
            continue;
        }
        sc++;
    }
    return x;
}

fs huajian(fs x)
{
    if(x.u<0)x.fuhao=!x.fuhao,x.u=-x.u;
    if(x.d<0)x.fuhao=!x.fuhao,x.d=-x.d;
    int gc=gcd(x.u,x.d);
    x.u/=gc;
    x.d/=gc;
    return x;
}
void printans(fs u)
{
    if(u.u==0)
    {
        printf("0");
        return;
    }
    if(u.fuhao)printf("-");
    if(u.d==1)printf("%d",u.u);
    else printf("%d/%d",u.u,u.d);
}

void solve(int a,int b,int c)
{
    int delta=(b*b-4*a*c);
    if(delta<0)
    {
        printf("NO\n");
        return;
    }
    if(delta==0 || pfs(delta)>0)
    {
        fs u={-b,2*a,0};
        if(a>0)u.u+=pfs(delta);
        else u.u-=pfs(delta);
        u=huajian(u);
        printans(u);
        printf("\n");
        return;
    }
    int newde=spfyz(delta);
    int xs=pfs(delta/newde);
    fs u={-b,2*a,0};
    fs v={xs,2*a,0};
    u=huajian(u);
    if(u.u!=0)printans(u);
    if(u.u!=0)printf("+");

    v=huajian(v);
    if(v.u==v.d)printf("sqrt(%d)",newde);
    else if(v.d==1)printf("%d*sqrt(%d)",v.u,newde);
    else if(v.u==1)printf("sqrt(%d)/%d",newde,v.d);
    else printf("%d*sqrt(%d)/%d",v.u,newde,v.d);
    printf("\n");
}

int main()
{

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    scanf("%d%d",&T,&M);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        solve(a,b,c);
    }

    return 0;
}
