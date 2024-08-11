#include<bits/stdc++.h>
using namespace std;
const int N=2000005,M=8005;
int n;
char c[N];
int st[N],top;
long long ans;
void work1()
{
    for(int i=1;i<=n;i++)
    {
        top=0;
        for(int j=i;j<=n;j++)
        {
            if(top&&c[st[top]]==c[j]) top--;
            else st[++top]=j;
            if(top==0) ans++;
        }
    }
    printf("%lld\n",ans);
}
void work2()
{
    for(int i=1;i<=n;i++)
    {
        top=0;
        for(int j=i;j<=n;j++)
        {
            if(top&&c[st[top]]==c[j]) top--;
            else st[++top]=j;
            if(top==0) ans++;
            if(top>50) break;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf(" %c",&c[i]);
    if(n<=8000) work1();
    else work2();
    return 0;
}
