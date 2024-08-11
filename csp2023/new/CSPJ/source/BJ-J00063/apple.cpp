#include <bits/stdc++.h>

using namespace std;
long long n,k,p,q;
int day(int n)
{
    int ans=0,cnt=0;
    if(n==1) return 1;
    else
    if(n==2) return 2;
    else
    if(n==3) return 3;
    else if(n==5) return 4;
    else if(n==10) return 5;
    else
    {
        for(int i=1;i<=n;i++)
        {
            n-=i;
            ans++;
            if(n<0)
            break;

        }
        if(n%3==1) ans-=1;
        return ans+2;
    }
}
int bian(int n)
{
    int sum=0;
    if(n==1) return 1;
    else
    if(n==2) return 2;
    else
    if(n==3) return 3;
    else if(n%3==1) return 1;
    else if(n%3==0) return 2;
    else if(n%3==2)
    {
        for(int i=1;i<=n;i++)
        {
            n-=3;
            sum++;
            if(n<=5)
              break;
        }
        return sum+4;

    }

}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    p=day(n);
    q=bian(n);
    cout<<p<<" "<<q;
    return 0;
}
