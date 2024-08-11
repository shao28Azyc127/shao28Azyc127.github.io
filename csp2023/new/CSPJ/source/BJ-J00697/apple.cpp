#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("apple.in","r",stdin);
    freopen ("apple.out","w",stdout);
    long long n,m=0,a,i,q;
    cin>>n;
    a=n;
    for (i=0;a>0;i++)
    {
        if (a%3!=0)
        {
            if (a%3==1&&m==0)
            {
                q=i+1;
                m=1;
            }
            a--;
        }
        a-=a/3;
    }
    cout<<i<<" "<<q<<endl;
    return 0;
}
