#include<bits/stdc++.h>
#pragma GCC(2)
using namespace std;
long  long n , d  , atmp = 0 , oil = 0 , cnt = 0;
int v[100005] , a[100005] ;
long long road(int m)
{
    if(m == 0)
    {
        return 0;
    }
    atmp = 0;
    for(int i = 0 ; i < m ; i++)
    {
        if(a[i] < a[atmp] && i != m - 1)
        {
            atmp = i;
        }
    }
    cnt = 0;
    for(int i = atmp ; i < m - 1 ; i++)
    {
        cnt += v[i];
    }
    oil = road(atmp) + ceil(1.0 * cnt / d) * a[atmp];
    return oil;
}
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin >> n >> d;
    n--;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &v[i]);
    }
    n++;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" ,  &a[i]);
        if(a[i] < a[atmp] && i != n - 1)
        {
            atmp = i;
        }
    }
    if(atmp == 0)
    {
        for(int i = 0; i < n - 1 ; i++)
        {
            cnt += v[i];
        }
        oil = ceil(1.0 * cnt / d) * a[atmp];
    }
    else
    {
        cout << road(n);
        return 0;
    }
    cout << oil;
    return 0;
}
