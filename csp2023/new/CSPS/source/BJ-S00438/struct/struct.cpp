#include <bits/stdc++.h>
using namespace std;
int ma[6][10],vis[10],cur,a[20],n,res;
bool fl=0;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
bool check()
{
    int index[4],cnt=0,top=0;
    for(int i=1;i<=cur;i++)
    {
        cnt=0,top=0;
        memset(index,0,sizeof index);
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=cur;k++)
            {
                if(a[k]!=ma[j][k])
                    cnt++,index[top]=i,top++;
            }
            if(cnt>2) return false;
            if(cnt==1) continue;
            if(cnt==0) return false;
            if(cnt==2&&index[1]-index[0]!=1) return false;
            fl=0;
            if(cnt==2)
            {
                int tmp1=a[index[0]],tmp2=a[index[1]];
                int u=0;
                while(u!=10)
                {
                    u++;
                    tmp1=(tmp1+1)%10;
                    tmp2=(tmp2+1)%10;
                    if(tmp1==ma[j][index[0]]&&tmp2==ma[j][index[1]])
                        fl=true;
                }
            }
            if(!fl) return false;
        }
    }
    return true;
}
void solve(int u)
{
    if(cur==6)
    {
        if(check()) res++;
        return ;
    }
    for(int i=0;i<10;i++)
    {
        a[cur]=i;
        cur++;
        solve(u+1);
        cur--;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    if(n==1)
    {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        cout<<81<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            ma[i][j]=read();
    solve(0);
    cout<<res<<"\n";
    return 0;
}
