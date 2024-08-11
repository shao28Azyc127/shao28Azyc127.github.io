#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int sum=0,x,f,i;
    cin>>x;
    f=x;
    while(x!=0)
    {
        if(x%3==0)
            x-=x/3;
        else
        {
            x-=x/3;
            x--;
        }
        sum++;
    }
    cout<<sum<<' ';
    for(i=1;f;i++)
    {
        if(f%3==0)
        {
            cout<<i;
            return 0;
        }
        else
        {
            f-=f/3;
            f--;
        }
    }
    cout<<i;
    return 0;
}
