#include<bits/stdc++.h>
using namespace std;
int n,a[100005],sum[100005],d,c[100005],ans,minn;
int b[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i=1;i<n;i++)
    {
        cin >> a[i];
    }
    int last=a[n];
    for (int i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    minn=b[1];
    int s=0;
    int y=0;
    for (int i=1;i<=n;i++)
    {
        if (b[i]<minn)
        {
            int f;
            int l=sum[i]-sum[s]-y;
            if (l%d==0)
                f=l/d;
            else
            {
                f=l/d+1;
                y+=d*f-l;
            }
            ans+=minn*f;
            minn=b[i];
            s=i;
            //cout << i << " " <<f << "\n";
        }
    }
    cout << ans;
    return 0;
}
/*5 4
10 10 10 10 10
9 8 9 6 5
*/
