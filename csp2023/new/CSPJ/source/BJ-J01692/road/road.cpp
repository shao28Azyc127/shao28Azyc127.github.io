#include<bits/stdc++.h>
using namespace std;

long long a[100005];
long long you[100005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    long long x=1;
    long long yugong=0;
    long long sum=0;
    cin >> n >> d;
    for (int i=2;i<=n;i++)
        scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++)
        scanf("%lld",&you[i]);
    you[n]=-1;
    while (x<n)
    {
        long long lon=0;
        for (int i=x+1;i<=n;i++)
        {
            lon=lon+a[i];
            if (you[x]>you[i])
            {
                if ((lon-yugong)%d==0)
                {
                    yugong=0;
                    sum=sum+(lon-yugong)/d*you[x];
                    //cout << 1 << " "  << yugong << endl;
                }
                else
                {
                    sum=sum+((lon-yugong)/d+1)*you[x];
                    yugong=((lon-yugong)/d+1)*d+yugong-lon;
                    //cout << 2 << " "  << yugong << endl;
                }
                //cout << x << " " << sum << endl;
                x=i;
                break;
            }
        }
    }
    cout << sum << endl;

    return 0;
}
