#include <iostream>
#include <cstdio>
using namespace std;
int n,d;
int v[100005];
int a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n >> d;
    int mm=0;
    for(int i=1;i<n;i++)
    {
        cin >> v[i];
        mm+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int s;
    if(mm%d==0)
    {
        s=mm/d;
    }
    else
    {
        s=mm/d+1;
    }
    cout << s*a[1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
