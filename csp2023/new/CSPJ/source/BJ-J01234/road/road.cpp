#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int n, d,ans;

int v[100005], p[100005], s[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int last = 1, left = 0;
    scanf("%d%d", &n, &d);
    for(int i=1; i<n; i++)
    {
        scanf("%d", &v[i]);
        s[i+1] = s[i] + v[i];
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &p[i]);
    }
    for(int i=2; i<=n; i++)
    {
        if(i==n)
        {
            int t = s[i]-s[last]-left;
            ans += p[last]*ceil(double(t)/double(d));
            break;
        }
        if(p[i]<p[last])
        {
            int t = s[i]-s[last]-left;
            if(t%d==0)
            {
                ans += p[last]*(t/d);
                last = i;
                left = 0;
            }
            else
            {
                ans += p[last]*ceil(double(t)/double(d));
                last = i;
                left = ceil(double(t)/double(d))*d-t;
            }
        }

    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
