#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 1e5;
int v[N + 5],a[N + 5];
int n,d;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    int point = 1,len = 0,i = 0;
    long long ans = 0,c = 0;
    while(point <= n)
    {
        for(i = point;i <= n;i++)
        {
            if(a[i] < a[point])
            {
                break;
            }
            len += v[i];
        }
        ans += ceil(1.0 * (len - c) / d) * a[point];
        c += ceil(1.0 * (len - c) / d) * d - len;
        point = i;
        len = 0;
    }
    cout << ans;
    return 0;
}
