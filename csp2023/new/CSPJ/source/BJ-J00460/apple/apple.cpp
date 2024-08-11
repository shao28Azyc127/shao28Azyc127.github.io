#include<bits/stdc++.h>
using namespace std;
bool a[1000000005];
int n,f=0,t=0;
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)return false;
    }
    return true;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>n;
    while(1)
    {
        t++;
        int cnt=1;
        int ans=5;
        while(cnt<=n)
        {


                if(a[cnt]==1)
                {
                    cnt++;


                }
                 else if(a[cnt]==0&&ans<=2)
                {
                    cnt++;
                    ans++;
                }
                 else if(a[cnt]==0&&ans>2)
                {
                    if(cnt==n)f=t;
                    a[cnt]=1;
                    cnt++;
                    ans=1;
                }



            }
              if(check())break;
    }

        cout<<t<<" "<<f;
    return 0;
}
