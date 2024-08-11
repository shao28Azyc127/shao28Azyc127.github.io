#include <bits/stdc++.h>
using namespace std;
long long n,ans;
char c[810];
bool check (int l,int r)
{
    char a[810],b[810];
    int x=0,y;
    for(int i=l;i<=r;i++)
        a[++x]=c[i];
    //cout<<x<<" "<<s<<endl;
    while(x>0)
    {
        y=0;
        for(int i=1;i<=x;i++)
        {
            if(a[i]==a[i+1])
            {
                //cout<<l<<" "<<r<<" "<<i<<" "<<i+1<<endl;
                i++;
            }
            else
                b[++y]=a[i];
        }
        for(int i=1;i<=y;i++)
            a[i]=b[i],b[i]=0;
        for(int i=y+1;i<=x;i++)
            a[i]=0;
        if(y==x)
            return 0;
        x=y;
    }
    //cout<<l<<" "<<r<<endl;
    return 1;
}
int main()
{

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int k=2;k<=n;k+=2)
        for(int j=1;j+k-1<=n;j++)
            if(check(j,j+k-1))
                ans++;
    cout<<ans<<endl;
    return 0;
}