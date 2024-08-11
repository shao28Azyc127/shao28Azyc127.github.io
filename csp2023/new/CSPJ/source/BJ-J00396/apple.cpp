#include<iostream>
#include<cstdio>
using namespace std;
bool a[1000000001];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,ans=0;
    cin >> n;
    while(true)
    {
        int cnt1=0;
        bool flag=true,flag1=false;
        for(int i=1;i<=n;i++)
        {
             if(a[i]==false)
             {
                 cnt1++;
                 if(cnt1%3==1)
                 {
                     a[i]=true;
                     if(a[i]==n)
                     {
                         flag1=true;
                     }
                 }
             }
        }
        cnt++;
        if(flag1==false)
        {
            ans++;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==false)
            {
                flag=false;
            }
        }
        if(flag==ture)
        {
            break;
        }
    }
    cout << cnt << " " << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include<iostream>
using namespace std;
bool a[1000000000]={};
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,ans=0;
    cin >> n;
    while(true)
    {
        int cnt1=0;
        bool flag=true,flag1=false;
        for(int i=1;i<=n;i++)
        {
             if(a[i]==false)
             {
                 cnt1++;
                 if(cnt1%3==1)
                 {
                     a[i]=true;
                     if(a[i]==n)
                     {
                         flag1=true;
                     }
                 }
             }
        }
        cnt++;
        if(flag1==false)
        {
            ans++;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==false)
            {
                flag=false;
            }
        }
        if(flag==ture)
        {
            break;
        }
    }
    cout << cnt << " " << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
