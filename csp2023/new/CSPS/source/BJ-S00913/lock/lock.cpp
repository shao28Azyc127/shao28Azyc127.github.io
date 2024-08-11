#include<bits/stdc++.h>
using namespace std;
const int N=20,M=110,Q=1000010;
int n,t1,t2,cnt,tmp,a[N][N],d[N];
bool vis[N],vis2[N],vis3[M],qwq[Q],q[N<<1];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    for(int i=1;i<=5;i++) vis[i]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
    if(n==1) {printf("81\n"); return 0;}
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=5;j++)
            if(a[i][j]!=a[i+1][j]) vis[j]=1;
    }
    for(int i=1;i<=5;i++)
        if(vis[i] && !t1) t1=i;
        else if(vis[i]) t2=i;
    if(!t1) {puts("81"); return 0;}
    for(int i=1;i<=5;i++) vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        for(int j=1;j<=5;j++) tmp=tmp*10+a[i][j];
        if(qwq[tmp]) vis[i]=1;
        qwq[tmp]=1;
    }
    if(t1 && t2)
    {
        bool fl=0;
        for(int i=1;i<=n;i++) d[i]=a[i][t1]-a[i][t2];
        for(int i=1;i<n;i++)
            if(d[i]!=d[i+1]) fl=1;
        if(fl)
        {
            bool fl1=1,fl2=1; int lst1=-1,lst2=-1;
            for(int i=1;i<=n;i++)
            {
                if(q[d[i]+10]) continue;
                q[d[i]+10]=1; lst1=-1; lst2=-1; fl1=1; fl2=1;
                for(int j=1;j<=n;j++)
                {
                    if(d[j]==d[i]) continue;
                    if(fl1 && (lst1!=-1 && a[j][t1]!=lst1)) fl1=0;
                    else lst1=a[j][t1];
                    if(fl2 && (lst2!=-1 && a[j][t2]!=lst2)) fl2=0;
                    else lst2=a[j][t2];
                    //cout<<j<<" "<<fl1<<" "<<fl2<<" *"<<endl;
                }
                cnt+=fl1+fl2;
                //cout<<i<<" "<<d[i]<<" "<<cnt<<endl;
            }
            printf("%d\n",cnt);
            return 0;
        }
        for(int i=1;i<=n;i++)
            if(!vis[i]) vis2[a[i][t1]]=1;
        for(int i=0;i<=9;i++)
            if(!vis2[i]) cnt++;
        printf("%d\n",cnt);
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(!vis[i]) vis2[a[i][t1]]=1;
        for(int i=0;i<=9;i++)
            if(!vis2[i]) cnt++;
        if(cnt==8 && (t1==1 || t1==5)) cnt+=2;
        else if(cnt==8) cnt+=4;
        printf("%d\n",cnt);
    }
    return 0;
}
