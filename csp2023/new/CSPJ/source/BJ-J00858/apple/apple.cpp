#include <bits/stdc++.h>
using namespace std;
int n,s1,s2;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    s2=1000000000;
    int i=0;
    while(n>0)
    {
        i++;
        int a=(n-1)/3+1;
        if(n%3==1)
        {
            s2=min(s2,i);
        }
        n=n-a;
    }
    s1=i;
    cout<<s1<<" "<<s2;
    return 0;
}