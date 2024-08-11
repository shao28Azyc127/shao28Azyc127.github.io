#include<iostream>
#include<vector>
using namespace std;

int n,a[100005],b[100005],c[100005],ans = -1;

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i] >> c[i];

    bool flag = false;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        if(u != i || v != i + 1) flag = true;
    }

    if(flag = true)
    {
        for(int i=1;i<=n;i++)
        {
            int tm = i,h = 0;
            while(h < a[i])
            {
                h += max(b[i] + tm * c[i], 1);
                tm++;
            }
            ans = max(tm,ans);
        }
    }
    cout << ans << endl;
    return 0;
}
