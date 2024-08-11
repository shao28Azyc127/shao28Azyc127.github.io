#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int day = 0,ans;
void e(int i)
{
    for(int j = i;j <= n;j++)
    {
        a[j] = a[j+1];
    }
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int u = n;
    for(int i = 1;i <= n;i++)
    {
        a[i] = i;
    }
    while(n > 0)
    {
        int jn = 0,e_i = 1,ig = 0;
        int e_l[1000000] = {};
        for(int i = 1;i <= n;i+=3)
        {
            if(a[i] == u)
            {
                ans = day+1;
            }
            e_l[e_i++] = i-ig;
            jn++;
            ig++;
        }
        for(int i = 1;i < e_i;i++)
        {
            e(e_l[i]);
        }
        n-=jn;
        day++;
    }
    cout<<day<<" "<<ans;
    return 0;
}
