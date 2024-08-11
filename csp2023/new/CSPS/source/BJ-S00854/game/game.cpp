#include<bits/stdc++.h>
using namespace std;
int n,f[2000006],ans;
char s[2000006],ch[2000006];
int ck(int x,int y)
{
    if(x>=y)return 0;
    if((y-x+1)%2>0)return 0;
    for(int i=x;i<=y;i++)
        ch[i]=s[i];
    int fl=1,kk=1;
    for(int k=1;k==k;k++)
    {
        int tmp=-1;
        fl=1,kk=0;
        for(int i=x;i<=y;i++)
        {
            if(ch[i]==' ')
            {
                continue;
            }
            if(ch[i]==ch[tmp])ch[i]=ch[tmp]=' ',tmp=-1,kk=1;
            tmp=i;fl=0;
        }
        if(fl==1)return 1;
        if(kk==0)return 0;
    }
    return 0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>s[i];
    for(int st=1;st<=n;st++)
    {
        for(int ed=st+1;ed<=n;ed+=2)
        {
            if(ck(st,ed))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
