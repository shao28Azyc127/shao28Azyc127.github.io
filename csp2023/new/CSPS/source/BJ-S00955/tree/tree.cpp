#include <bits/stdc++.h>

using namespace std;

long long n,ans;

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n ;
    long long i,a,b,c,d,e;
    for(i=0;i<n;i++)
    {
        e=0;
        cin >> a >> b >> c ;
        for(d=1;e<a;d++)
            e+=max((long long)1,b+c*d);
        ans=max(ans,d);
    }
    cout << max(n,ans) ;
}
