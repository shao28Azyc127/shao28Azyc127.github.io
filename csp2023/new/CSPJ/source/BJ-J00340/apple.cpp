#include<iostream>
#include<cstdio>
using namespace std;
long long n,d,m;
bool a[1000000005];
void apple()
{
    long long s;
    for(long long i=1;i<=n;i++)
    {
        if (a[i]==0)
        {
            s=i;
            d++;
            if(s==n)
            {
                m=d;
                return ;
            }
            break;
        }
        if (i==n and a[n]==1)
            return ;
    }
    a[s]=1;
    int sum=0;
    for(long long i=s;i<=n;i++)
    {
        if(a[i]==0)
        {

            if(sum==2)
            {
                a[i]=1;
                sum=0;
                if(i==n) m=d;
                continue;
            }
            sum++;
        }
    }
    apple();
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    apple();
    cout<<d<<" "<<m;
    return 0;
}
