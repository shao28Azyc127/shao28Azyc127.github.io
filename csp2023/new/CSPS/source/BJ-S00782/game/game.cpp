#include <bits/stdc++.h>
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
const int maxn=2e6+5;
int n;
char s[maxn];
int place[maxn];
struct blocks{
    int tot,left,right;
}block[maxn];
int cnt=0;
int sum;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    for (int i=1;i<=n;i++)
    {
        s[i]=getchar();
    }
    for (int i=1;i<n;i++)
    {
        if (a[i]==a[i]+1)
        {
            cnt++;
            sum++;
            place[cnt]=i;
        }
    }
    for (int i=1;i<=cnt;i++)
    {
        int l=place[i],r=l+1;
        while (a[l]==a[r])
        {
            l--;
            r++;
            sum++;
        }
        block[i].left=l;
        block[i].right=r;
        block[i].tot=(block[i].right-block[i].right)/2;
    }
    cout << sum;
    return 0;
}
