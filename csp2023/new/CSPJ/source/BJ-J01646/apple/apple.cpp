#include<bits/stdc++.h>
using namespace std;
int t1,t2;
int n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    //cin>>n;
    int x=n;
    if(n<=3) t1=n;
    else
    {
        while(x/3!=0)
        {
            x/=3;
            x*=2;
            t1++;
        }
        if(n%3!=1)
        t1+=3;
        else
        t1+=2;
    }
    if(n%3==1) t2=1;
    else
    {
        if(n%3==2) t2=t1;
        if(n%3==0) t2=n/3;

    }
    cout<<t1<<" "<<t2;
    return 0;
}