#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2;
int flag;
bool a[1000000010],t;
bool harley()
{
    for(int i=1;i<=n;i++) if(a[i]==0) return 0;
    return 1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(long long i=1;;i++)
    {
        flag=0;
        for(long long j=1;j<=n;j++)
        {
            if(a[j]==0&&flag==0)
            {
                a[j]=1;
                flag++;
                if(flag==3) flag=0;
            }
            else if(a[j]==0&&flag!=0)
            {
                flag++;
                if(flag==3) flag=0;
            }
        }
        if(a[n]==1&&t==0) ans2=i,t=1;
        if(harley())
        {
            ans1=i;
            break;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
