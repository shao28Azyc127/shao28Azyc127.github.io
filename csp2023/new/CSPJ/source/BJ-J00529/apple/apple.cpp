#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,s=0,m;
    cin >> n;
    while(n>0)
    {
        if(n%3==1)
        {
            m=s+1;
        }
        int k=n/3+1;
        n=n-k;
        s++;
    }
    cout << s << " " << m;
    return 0;
}
