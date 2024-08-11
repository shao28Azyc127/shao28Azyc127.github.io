#include <iostream>
#include <cstdio>
using namespace std;
int u[1000010],s[1000010],a[1000010],n,d,ss[1000010];
long long t,sum,g[1000010];
int main()
{
    //((s[n]-s[i-1]-mu|qian|bu|jia|you|nen|pao|duo|shao|gong|li)/d+((s[n]-s[i-1]-mu|qian|bu|jia|you|nen|pao|duo|shao|gong|li)%d==0?0:1))*a[i]
    freopen("road.in","r",stdin);
    freopen("road1.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++)
    {
        cin >> u[i];
        s[i] = u[i] + s[i-1];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 2;i < n;i++)
    {
        g[i] = 10000000;
        for(int j = 1;j < i;j++)
        {
            g[i] = min(g[i],((s[i-1]-s[j-1]-t)/d+((s[i-1]-s[j-1]-t)%d==0?0:1))*a[j]-ss[i-1]+ss[j]);
            //cout << ((s[i-1]-s[j-1]-t)/d+((s[i-1]-s[j-1]-t)%d==0?0:1))*a[j] << '?' << s[i-1] << '|' << s[j-1] << '|' << i << '|' << j-1 << '|' << '?' << '\n';
        }
        ss[i] = ss[i-1]+g[i];
        //cout << '!' << g[i] << '!';
    }
    for(int i = 1;i <= n;i++)
    {
        sum+=g[i];
    }
    cout << sum;
    return 0;
}
