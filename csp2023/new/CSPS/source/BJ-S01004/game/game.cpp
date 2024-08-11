#include<iostream>
#include<list>
using namespace std;
const int maxn=2e6;
char ch[maxn];
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int ans=0;
    int n;scanf("%d",&n);
        scanf("%s",ch+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            short b[maxn];register int cnt=1;
            for(int t=i;t<=j;t++)
            {
                b[cnt++]=ch[t];
                while(cnt>1&&b[cnt-1]==b[cnt-2])cnt-=2;
            }
            for(int t=1;t<cnt;t++);
            if(cnt==1)ans++;
            int p1=0,p2=0;
        }
    }    
    printf("%d",ans);
    return 0;
}