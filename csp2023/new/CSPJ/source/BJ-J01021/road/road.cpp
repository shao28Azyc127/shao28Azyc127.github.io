#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long ans = 0;
    int a,b,c;
    int n,d;
    cin >> n >> d;
    for(int i=1;i<n;i++)
    {
        cin >> a;
        ans += a;
    }
    cin >> b;
    for(int i=1;i<n;i++)
    {
        cin >> c;
    }
    cout << ans * b / d;
    return 0;
}
