#include <bits/stdc++.h>
using namespace std;
char s[20];
bool vis[20];
long long int ans=0;
void match(int l,int r){
     
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(register int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(register int i=1;i<=n-1;i++)
    {
        match(i,i+1);
    }
    for(register int i=1;i<=n-3;i++)
    {
        match(i,i+3);
    }
    for(register int i=1;i<=n-5;i++)
    {
        match(i,i+5);
    }
    for(register int i=1;i<=n-7;i++)
    {
        match(i,i+7);
    }
    for(register int i=1;i<=n-9;i++)
    {
        match(i,i+9);
    }
    printf("%lld",ans);
    return 0;
}
