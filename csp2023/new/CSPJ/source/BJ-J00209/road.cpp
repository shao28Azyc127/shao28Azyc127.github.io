#include <iostream>
#include <cstdio>
using namespace std;
int a[100010];
int b[100010];
int s[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for(int i=1; i<n; i++)
    {
        cin >> a[i];
    }
    s[0]=1e6;
    for(int i=1; i<=n; i++)
    {
        cin >> b[i];
        s[i]=min(s[i-1],b[i]);
    }
    int mc=0;
    long long cs=0;
    for(int i=1; i<n; i++)
    {
        int p=a[i]-mc;
        cs+=1LL*(p+d-1)/d*s[i];
        mc=(p+d-1)/d*d-p;
    }
    cout << cs;
    return 0;
}