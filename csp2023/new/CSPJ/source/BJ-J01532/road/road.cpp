#include<bits/stdc++.h>
using namespace std;
int n,d;
const int N = (int) 1e5 + 10;
int b[N];
int a[N];
struct C
{
    int x,y;
}; C c[N];
int zhao(int m)
{
    for (int i = 0;i < n;i++)
    {
        if(b[i] == m)
        {
            return i;
        }
    }
}
int cmp (C a,C b)
{
    if(a.x != b.x)
    {
        return a.x < b.x;
    }
    return a.y < b.y;
}
int main ()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (int i = 0;i < n - 1;i++)
    {
        scanf("%d",&a[i]);
    }
    int m = 0;
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&b[i]);
        c[i].x = b[i];
        c[i].y = i;
    }
    sort(c,c + n,cmp);
    int s;
    int sum = 0;
    int m1 = n - 1;
    int lin = 0;
    while(true)
    {
        s = zhao(c[m].x);
        m++;
        while(c[m].y > s)
        {
            m++;
        }
        int w = 0;
        for (int i = m1;i > s;i--)
        {
            w += a[i - 1];
        }
        sum += (w + lin) / d * b[s];
        lin = (w + lin) % d;
        m1 = s;
        if(s == 0)
        {
            break;
        }
    }
    printf("%d",sum);
    return 0;
}
