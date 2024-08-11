#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt1=1,cnt2=1,cnt3=2,cnt4=4;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        if(cnt1>=n)
        {
            cout<<cnt2<<" ";
            break;
        }
        cnt1=cnt1+cnt2;
        cnt2++;
    }
    if(n%3==1)
    {
        cout<<"1";
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        if(cnt3==n)
        {
            cout<<"2";
            return 0;
        }
        cnt3=cnt3+cnt4;
        if(cnt4==4)
        {
            cnt4=5;
        }
        else
        {
            cnt4=4;
        }
    }
    int cnt5=3,cnt6=6;
    for(int i=3;i<=n;i++)
    {
        if(cnt5==n)
        {
            cout<<"3";
            return 0;
        }
        cnt5=cnt5+cnt6;
        if(cnt6==6)
        {
            cnt6=8;
        }
        else
        {
            cnt6=6;
        }
    }
    int cnt7=4,cnt8=10;
    for(int i=4;i<=n;i++)
    {
        if(cnt7==n)
        {
            cout<<"4";
            return 0;
        }
        cnt7=cnt7+cnt8;
        if(cnt8==10)
        {
            cnt8=12;
        }
        else
        {
            cnt8=10;
        }
    }
    cout<<cnt2;
    return 0;
}
