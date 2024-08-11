#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,a[20000],b[100000],ans = 0;
    cin >> n >> m;
    for(long long i = 0;i < n - 1;i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    for(long long i = 0;i < n;i++)
    {
        cin >> b[i];
    }
    if(ans % m == 0)
    {
        cout << b[0] * ans / m;
    }
    else
    {
        cout << b[0] * (ans / m + 1);
    }
    return 0;
}

