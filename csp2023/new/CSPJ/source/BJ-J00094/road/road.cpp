#include<iostream>
using namespace std;

long long n,d,v[100010],a[100010],s[100010],minn,minx,ans;

int main()
{
    cin >> n >> d;
    for(int i = 1;i < n;i++)
        cin >> v[i];
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i < n;i++)
    {
        s[i] = s[i-1]+v[i];
    }
    minn = a[1],minx = 1;
    for(int i = 2;i <= n;i++)
    {
        if(a[i] < minn)
        {
            ans += (s[i-1] - s[minx-1]) / d * a[minx];
            minn = a[i],minx = i;
        }
    }
    if(minx != n) ans += (s[n-1] - s[minx-1]) / d * a[minx];
    cout << ans <<"\n";
    return 0;
}