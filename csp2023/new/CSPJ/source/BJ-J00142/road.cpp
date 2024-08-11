#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >>n >>d;
    for(int i = 1; i  <= n-1; i++)
        cin >>v[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int sum = 0;
    int cur = 1;
    while(cur <= n)
    {
        sum += int(v[cur]/d*a[cur]+0.9);
        cur++;
    }
    cout <<sum;
    return 0;
}
