#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("apple.in","r",stdin);
    freopen ("apple.out","w",stdout);
    int n,ans1=0,ans2=0,b;
    bool f=0;
    cin >>n;
    int k=n;
    b=n;
    while (k>0)
    {
        if (k%3==0) k-=k/3;
        else k-=k/3+1;
        ans1++;
    }
    cout <<ans1<<" ";
    k=n;
    while (f==0)
    {
        if (k%3==1)
        {
            ans2++;
            break;
        }
        if (k%3==0) k-=k/3;
        else k-=k/3+1;
        ans2++;
    }
    cout <<ans2;

    return 0;
}
