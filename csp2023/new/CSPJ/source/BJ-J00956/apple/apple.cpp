#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,a[10000000020]={},s,d=0,f=1,ans;
    cin>>n;
    s=n;
    while(s>0)
    {
        d++;
        for(int i=1;i<=n;i+=3)
        {
            a[i]=1;
            s--;
            if(n==i&&f==1)
            {
                ans=d;
                f=0;
            }
        }
        for(int i=1;i<=s;i++)
        {
            a[i]=0;
        }
        n=s;
    }
    cout<<d<<" "<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
