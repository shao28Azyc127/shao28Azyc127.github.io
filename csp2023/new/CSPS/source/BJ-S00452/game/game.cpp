#include<bits/stdc++.h>
using namespace std;

int n;
char a[2000010];
int ans;

int Right(int x,int l)
{
    int ans=0;
    stack<char> S;
    for(int i=x;i<=l;i++)
    {
        if( S.empty() || a[i]!=S.top() )
        {
            S.push(a[i]);
        }
        else
        {
            S.pop();
            if(S.empty())ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    char checkword;
    scanf("%d",&n);
    scanf("%c",&checkword);
    if(checkword==10)for(int i=1;i<=n;i++)scanf("%c",&a[i]);
    else for(int i=1;i<=n;i++)scanf("%c",&a[i]),a[1]=checkword;
    for(int i=1;i<=n;i++)
    {
        ans+=Right(i,n);
    }
    printf("%lld",ans);
    return 0;
}
