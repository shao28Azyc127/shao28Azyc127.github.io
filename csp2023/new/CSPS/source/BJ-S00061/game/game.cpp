#include<bits/stdc++.h>
using namespace std;
int n;
char lis[2000010]={};
long long ans=0;
char sta[2000010]={};
int tag=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>lis;
    for(int f=0;f<n;f++)
    for(int t=f+1;t<n;t++)
    {
        while(tag>0)
        {
            sta[tag]=0;
            tag--;
        }
        for(int k=f;k<=t;k++)
        {
            if(tag&&sta[tag]==lis[k])
            {
                sta[tag]=0;
                tag--;
            }
            else
            sta[++tag]=lis[k];
        }
        if(tag==0)
        ans++;
    }
    printf("%lld",ans);
    return 0;
}
