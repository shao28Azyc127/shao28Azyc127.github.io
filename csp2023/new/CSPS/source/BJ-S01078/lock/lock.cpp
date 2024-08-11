#include <bits/stdc++.h>
using namespace std;

const int NR=100;
int a[NR][NR],dis[NR][NR],b[NR];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
    int ans=0;
    for(int i=0;i<=9;i++) for(int j=0;j<=9;j++) if(j<=i) dis[i][j]=i-j; else dis[i][j]=i-j+10;
    for(int x=0;x<=99999;x++)
    {
        b[1]=x%10;
        b[2]=(x/10)%10;
        b[3]=(x/100)%10;
        b[4]=(x/1000)%10;
        b[5]=(x/10000)%10;
        bool flag=true;
        for(int num=1;num<=n;num++)
        {
            bool ok=false;
            int now=0;
            for(int i=1;i<=5;i++)
            {
                if(a[num][i]==b[i]) now++;
            }
            if(now==4) ok=true;
            for(int i=1;i<=4;i++)
            {
                bool now_ok=true;
                for(int j=1;j<=5;j++)
                {
                    if(i==j||j==i+1) continue;
                    if(a[num][j]!=b[j]) now_ok=false;
                }
                if(dis[a[num][i]][b[i]]!=dis[a[num][i+1]][b[i+1]]) now_ok=false;
                if(now_ok==true) ok=true;
            }
            if(now==5) ok=false;
            if(ok==false) flag=false;
        }
        if(flag==true) ans++;
    }
    printf("%d",ans);
    return 0;
}
