#include<bits/stdc++.h>
using namespace std;
long long v[1005000],a[1005000];
long long n,d,y,yy,s,pianyi=0,lucheng=0,ans,pianyikg=1,didian;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    while(true)
    {
        if(pianyikg==1)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[j]<a[i])
                {
                    pianyi=j;
                    didian=pianyi;
                    break;
                }
            }
            if(pianyi==0)
            {
                pianyikg=0;
                didian=n;
            }
        }
        if(pianyikg==1)
        {
            for(int j=i;j<pianyi;j++)
            {
                lucheng+=v[j];
            }
        }else
        {
            for(int j=i;j<n;j++)
            {
                lucheng+=v[j];
            }
        }
        lucheng-=y;
        s=lucheng/d;
        if(lucheng%d!=0)
        {
            s++;
        }
        y=s*d;
        ans+=s*a[i];
        s=0;
        y-=lucheng;
        i=didian;
        lucheng=0;
        if(i==n)
            break;
    }
    cout<<ans;
    return 0;
}
