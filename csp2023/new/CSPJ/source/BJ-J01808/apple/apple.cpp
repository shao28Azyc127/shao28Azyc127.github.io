#include<bits/stdc++.h>
using namespace std;
int n,a[1000000009],l;
bool v[1000000009];
int f(int day,int n1,int n)
{
    if(n1==0) return day;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(k%3==0&&v[i]==true)
        {
            v[i]=false;
            k++;
            n1--;
            if(i==n) l=day+1;
        }
        else
        {
            continue;
        }
    }
    day++;
    return f(day,n1,n);
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    cout<<f(0,n,n)<<" "<<l;
    return 0;
}
