#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
char a[10],t1[10],t2[10];
int t,tot,tot1,h[100],maxn[100],sum;
struct node{
    string name;
    int m1,m2;
}e[100003],a1[100][1000];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            cin>>t1;
            if(mp[t1]==0)
                mp[t1]=++tot;
            int u=mp[t1];
            scanf("%d",&h[u]);
            for(int i=1;i<=h[u];i++)
            {
                cin>>a;
                if(a[0]=='b')
                a1[u][i].m1=1;
                if(a[0]=='s')
                a1[u][i].m1=2;
                if(a[0]=='i')
                a1[u][i].m1=4;
                if(a[0]=='l')
                a1[u][i].m1=8;
                maxn[u]=max(maxn[u],a1[u][i].m1);
                cin>>a;
                a1[u][i].name=a;

            }
            /*for(int i=1;i<=h[mp[t1]];i++)
            {
                a1[u][i].m2=maxn[u];
            }*/
            printf("%d %d\n",maxn[u]*h[u],maxn[u]);
        }
        if(op==2)
        {
            cin>>t1>>t2;
            if(mp[t1]!=0)
            {
                cout<<sum<<endl;
                int u=mp[t1];
                sum+=maxn[u]*h[u];

                for(int i=1;i<=h[u];i++)
                {
                    e[++tot1].name=t2+'.'+a1[u][i].name;
                    //cout<<e[tot1].name;
                    e[tot1].m1=a1[u][i].m1;
                    e[tot1].m2=maxn[u];
                }

            }
        }
    }

    return 0;
}
