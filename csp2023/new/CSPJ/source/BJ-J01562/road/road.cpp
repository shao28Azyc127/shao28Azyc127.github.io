#include <iostream>
using namespace std;
int v[100005];
int a[100005];
int main()
{
	freopen("road.in","R",stdin);
	freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for(int i=1;i<n;i++)
    {
        cin >> v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    long long ans=0;
    int now=1;
    long you=0;
    for(int i=2;i<=n;i++)
    {

        long youu=v[i-1]-you;
        youu=(youu+(d-1))/d;
        ans+=youu*a[now];
        you=youu*d-v[i];
        if(a[now]>a[i])
        {
        	now=i;
		}
    }
    cout <<ans;
    return 0;
}