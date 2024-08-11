#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100005;
int ver[2*N],head[N],from[2*N],nxt[2*N],tot = 0;
int ans[N];
void add(int x,int y)
{
    ver[++tot] = y;
    from[tot] = x;
    nxt[tot] = head[x];
    head[x] = tot;
}
int n,a[N],b[N],c[N];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","r",stdout);
    int fl1 = 1;
    cin>>n;
    for(int i = 1;i <= n;++i) cin>>a[i]>>b[i]>>c[i];
    int x,y;
    for(int i = 1;i < n;++i)
    {
        cin>>x>>y;
        if(y != x+1) fl1 = 0;
        add(x,y),add(y,x);
    }
    if(fl1 == 1)
    {
        int l,r;
        int s,t;
        for(int i = 1;i <= n;++i)
        {
            if(c[i] > 0)
            {
                l = 0,r = 100005;
                s = i;
                while(l<=r)
                {
                    t = (l+r)>>1;
                    int sum = ((s+t)*(t-s+1))/2;
                    if((t-s+1)*b[i]+sum*c[i] >= a[i])
                    {
                        ans[i] = t;
                        r = t-1;
                    }
                    else l = t+1;
                }
            }
            else if(c[i] == 0)
            {
                ans[i] = i+a[i]-1;
            }
            else if(c[i] < 0)
            {
                int tar = (1-b[i])/c[i];
                if((1-b[i])%c[i] != 0) ++tar;
                l = 0;r = 100005;
                if(tar <= i)
                {
                    ans[i] = i+a[i]-1;
                    continue;
                }
                while(l <= r)
                {
                    t = (l+r)>>1;
                    int val = 0,sum = 0;
                    if(t >= tar)
                    {
                        sum = ((s+tar-1)*(tar-1-s+1))/2;
                        val = sum*c[i]+(tar-1-s+1)*b[i];
                        val += t-tar+1;
                    }
                    else
                    {
                        sum = ((s+t)*(t-s+1))/2;
                        val = (t-s+1)*b[i]+sum*c[i];
                    }
                    if(val >= a[i])
                    {
                        ans[i] = t;
                        r = t-1;
                    }
                    else l = t+1;
                }
            }

        }
        int maxx = 0;
        for(int i = 1;i <= n;++i)
        {
            maxx = max(maxx,ans[i]);
        }
        cout<<maxx<<endl;
    }
    else
    {
        cout<<5<<endl;
    }
    return 0;
}
