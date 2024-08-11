#include <iostream>
#include <algorithm>
using namespace std;
int v[z],a[z],s[z];
bool f[z]
struct sta
{
    int id,p;
}b[z];
bool cmp(sta x,sta y)
{
    return x.p<y.p;
}
int main()
{
    int n,d,tot=0,sum=0;
    bool flag=0;
    cin>>n>>d;
    for(int i = 1; i<n; i++)
    {
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i];
        b[i].id=i;
        b[i].p=a[i];
    }
    sort(b+1,b+n+1,cmp);
    int i=0,q=0;
    while(1)
    {
        i++;
        sum+=b[i].p*((s[n]-s[b[i].id-1])/d);
        q=((s[n]-s[b[i].id-1])%d)
        for(int i = b[i].id; i<=n; i++)
        {
            f[i]=1;
        }
        for(int i = 1; i<=n; i++)
        {
            if(!f[i])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            cout<<sum<<endl;
            return 0;
        }
        flag=0;
    }
    return 0;
}