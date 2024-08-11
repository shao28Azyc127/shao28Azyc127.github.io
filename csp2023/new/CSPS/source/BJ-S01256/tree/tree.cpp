#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int N=1e5+9;
ll a[N]; int b[N], c[N];
ll height[N];
bool status[N];
int n;
int k=0;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i];

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin >> u >> v;
    }
    /*
    int day=-0x3f3f3f;
    for(int i=1; i<=n; i++)
    {
        int l=1; int r=1e9;
        while(l<r)
        {
            int mid=l+r>>1;
            if(mid*b[i]+(((i+mid)*(mid-i+1))/2)*c[i] >= a[i]) r=mid;
            else l=mid+1;
        }
        day=max(day+i, l);
    }
    cout << day << endl;
    */

    int day=1;

    for(; ; day++)
    {
        for(int i=1; i<=k; i++)
        {
            height[i] += max(1, b[i]+day*c[i]);
        }
        k++;
        bool flag=1;
        for(int i=1; i<=k; i++)
        {
            if(height[i]<a[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) break;
    }

    cout << day << endl;

    return 0;
}
