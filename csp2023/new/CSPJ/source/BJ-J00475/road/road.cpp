#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,a[100001] = {},v[100001] = {},l = 0,m = 0;
    cin >> n >> d;
    for(int i = 1;i < n;i++)
    {
        cin >> v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        if(v[i] > 0)
        {
            for(int j = i + 1;j < n;j++)
            {
                if(a[i] <= a[j])
                {
                    v[i]+=v[j];
                    v[j] = 0;
                }
                else
                {
                    break;
                }
            }
            m += (v[i] + d - l - 1)/d *a[i];
            l += (v[i] + d - l - 1)/d * d - v[i];
        }

    }
    cout << m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}