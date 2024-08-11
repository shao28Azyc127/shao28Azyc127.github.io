#include <bits/stdc++.h>
const int N=10010;
using namespace std;
int c,t,n,m,cnt,u,v;
char tfu;
int x[N];

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);

    for(int i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&m);
        memset(x,2,sizeof(n));
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                scanf("%c",&tfu);
                if(tfu=='U')
                {
                    scanf("%d",&u);
                    x[u]=2;
                    cnt++;
                }
                else if(tfu=='+')
                {
                    scanf("%d%d",&u,&v);
                    x[u]=x[v]=1;
                }
                else if(tfu=='-')
                {
                    scanf("%d%d",&u,&v);
                    x[u]=x[v]=0;
                }
                else if(tfu=='F')
                {
                    scanf("%d",&u);
                    x[u]=0;
                }
                else if(tfu=='T')
                {
                    scanf("%d",&u);
                    x[u]=1;
                }
                cout<<cnt;
            }
        }
        cout<<endl;
    }
    return 0;
}
