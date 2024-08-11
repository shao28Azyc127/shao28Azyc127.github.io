#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[105], b[105], c[105];
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(b[i] * b[i] - 4 * a[i] * c[i] < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << (sqrt(b[i] * b[i] - 4 * a[i] * c[i]) - b[i]) / (2 * a[i]) << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
