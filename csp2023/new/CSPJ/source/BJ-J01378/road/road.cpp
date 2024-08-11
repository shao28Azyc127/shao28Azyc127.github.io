#include<iostream>
#include<cstdio>
const int N = 2e5;
using namespace std;
int res = 0, n, d, a[N], v[N], i = 0, ld = 0;
bool flag = true, pd = true;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &d);
    for(int j = 0; j < n - 1; j++) scanf("%d", &v[j]);
    for(int j = 0; j < n; j++) scanf("%d", &a[j]);
    while(pd)
    {
        int t = i, ad = 0;
        for(i++; i < n && a[t] <= a[i]; i++);
        if(i >= n)
        {
			i = n - 1;
			pd = false;
	}
        for(int j = t; j < i; j++) ad += v[j];
        if(ad > ld)
        {
            ad -= ld;
            ld = 0;
        }
        else
        {
            ld -= ad;
            continue;
        }
        if(ad % d != 0)
        {
            res += (ad / d + 1) * a[t];
            ld += d - (ad % d);
        }
        else res += ad / d * a[t];
    }
    printf("%d", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
