#include<bits/stdc++.h>
using namespace std;
int v[100010],a[100010];
int main()
{
    double n,d,sum = 0;
    cin >> n >> d;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << ceil(v[i] / d) * a[1] << endl;
    return 0;
}