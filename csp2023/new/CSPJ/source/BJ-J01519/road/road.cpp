#include<iostream>
#include<cstring>
using namespace std;

int v[100005];
int a[100005];

int main ()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int o=0;
    cin >> n >> d;
    int ans=0;
    for(int i=2;i<=n;i++)cin >> v[i];
    for(int i=1;i<=n;i++)cin >> a[i];
    int x=1;
    int i;
    while(x!=n)
    {
        int lm=0;
        int am;
        for(i=x+1;i<=n;i++)
        {
            lm+=v[i];
            am=i;
            if(a[i]<=a[x])
            {
                break;

            }
        }
        o+=lm/d;
        ans+=lm/d*a[x];
        if(o*d<lm)
        {
            o+=1;
            ans+=a[x];
        }
        x=am;
        cout << x << " " ;
    }
    cout << ans << endl;
    return 0;
}
